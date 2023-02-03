#!/bin/bash

#This is the programm that searche all usefull arguments(false arguments will be ignored).
#Then, he will filter all usefull data.
#Next, he will appeal every folding-programm needed, give to gnuplot all data and erase temporary files.

#We search if there at least on argument. Return an error if not.
if (( $# == 0 )) ; then
    echo 'You need arguments!'
    exit 1
fi


#We search a '--help' argument.
#Return the manual if yes, an error if not.
for qu in `echo "$*" | cut -d ' ' -f 1` ; do
    if [ ${qu} = '--help' ] ; then
        echo 'Usage: ./Meteo.sh [OPTION]… -f name_file

Arguments and script options [DATA TYPE]:

    -h:			height for each station.

    -m:			maximum moisture for each station.

    -p<mode>	atmospheric pressure

        1:		produces at the output the minimum, maximum and average pressures per station in ascending order of station number

        2:		average pressures by date/time, sorted in chronological order.

    -t<mode>	temperature

        1:		produces at the output the minimum, maximum and average temperatures per station in ascending order of station number

        2:		average temperatures by date/time, sorted in chronological order.

    -w:			produces the average wind direction and speed for each station.

Arguments and script options [DATES]:

    -date min max:	the output data is in the date range [min...max] included. The format of the dates is a string of type YYYY-MM-DD (year-month-day).

Arguments and script options [SORT]:

    --avl:              sorting performed using an AVL type structure. This is the default sort if no sort type is selected

Arguments and script options [FILE]:

    -f name_file:     input file. This option is mandatory

Arguments and script options [LOCATION]:

    -F:			Metropolitan France + Corsica

    -G:			French Guyana

    -S:			Saint-Pierre and Miquelon

    -A:			Antilles

    -O:			Indian Ocean

    -Q:			Antarctica '
        exit 2
    fi

done



#We search the -f <file> argument.
#Return an error if no, and retain it if yes.
bool1=0 #Is there a '-f' sign somewhere?
bool2=0 #Is there a readable file after?
for qu in $* ; do 
    if [ $bool1 -eq 1 ] ; then
        if [ $bool2 -ne 1 ] ; then
            if [ -f ${qu} ] && [ -r ${qu} ] ; then
                bool2=1 #The file exist and is readable
                namefile="$qu"
            else
                echo 'There is no readable file after the -f'
                exit 3
            fi
        fi
    fi

    if [ ${qu} = '-f' ] && [ $bool1 -eq 0 ]; then
        bool1=1
    fi
done
if [ $bool1 -ne 1 ] && [ $bool2 -ne 1 ] ; then
    echo 'There is no file in argument'
    exit 4
fi


#We search a region argument.
#If there is one, he keep it. If too much of these arguments are here, return an error.
region=' '
bool1=0
for qu in $* ; do
    if [ ${qu} = '-F' ] || [ ${qu} = '-G' ] || [ ${qu} = '-S' ] || [ ${qu} = '-A' ] || [ ${qu} = '-O' ] || [ ${qu} = '-Q' ] ; then
        if [ $bool1 -eq 0 ] ; then
            region="$qu"
            bool1=1
        else
            echo 'There is too much argument about the region'
            exit 5
        fi
    fi

done


#We search a -d <date1> <date2> argument.
#If not well writen, return a specified error.
date1=' '
date2=' '
bool1=0 #Is there a -d argument?
bool2=0 #Can we read what is next the -d argument?
bool3=0 #Do the same, but one argument next.
for qu in $* ; do
    if [ $bool2 -eq 1 ] ; then
        date2="$qu"
	    if [ "${#qu}" -ne 10 ] ; then 
            echo "'Write the date in the format YYYY-MM-DD after the -d'"
            exit 6
	    fi
        if [ `echo "$date2" | cut -c 5` != '-' ] || [ `echo "$date2" | cut -c 8` != '-' ] ; then
            echo 'Write the date in the format YYYY-MM-DD after the -d'
            exit 7
        fi
        if [ `echo "$date2" | cut -c -4` -gt 2022 ] || [ `echo "$date2" | cut -c -4` -lt 2010 ] ; then
            echo 'Write a year between 2010 and 2022'
            exit 8
        fi
        if [ `echo "$date2" | cut -c 6-7` -gt 12 ] || [ `echo "$date2" | cut -c 6-7` -lt 1 ] ; then
            echo 'Write a mount between 1 and 12'
            exit 9
        fi
        if [ `echo "$date2" | cut -c 9-10` -gt 31 ] || [ `echo "$date2" | cut -c 9-10` -lt 1 ] ; then
            echo 'Write a day between 1 and 31'
            exit 10
        fi
        if [ `echo "$date2" | cut -c 6-7` = 2 ] || [ `echo "$date2" | cut -c 6-7` = 4 ] || [ `echo "$date2" | cut -c 6-7` = 6 ] || [ `echo "$date2" | cut -c 6-7` = 8 ] || [ `echo "$date2" | cut -c 6-7` = 10 ] || [ `echo "$date2" | cut -c 6-7` = 12 ] && [ `echo "$date2" | cut -c -4` -gt 30 ] ; then
            echo 'No more than 30 days for these mounths!'
            exit 11
        fi
        if [ $(( `echo "$date2" | cut -c -4` % 4 )) = 0 ] ; then
            if [ `echo "$date2" | cut -c 6-7` = 2 ] && [ `echo "$date2" | cut -c 9-10` -gt 29 ] ; then
                echo 'Write a day between 1 and 29 for this mounth'
                exit 12
            fi
        else
            if [ `echo "$date2" | cut -c 6-7` = 2 ] && [ `echo "$date2" | cut -c 9-10` -gt 28 ] ; then
                echo 'Write a day between 1 and 28 for this mounth'
                exit 13
            fi
        fi
        if [ `echo "$date2" | cut -c -4` -lt `echo "$date1" | cut -c -4` ] ; then
            echo 'the second date need to be higher than the first one'
            exit 14
        fi
        if [ `echo "$date2" | cut -c -4` -eq `echo "$date1" | cut -c -4` ] ; then
            if [ `echo "$date2" | cut -c 6-7` -lt `echo "$date1" | cut -c 6-7` ] ; then
                echo 'the second date need to be higher than the first one'
                exit 15
            fi
        fi
        if [ `echo "$date2" | cut -c -4` -eq `echo "$date1" | cut -c -4` ] ; then
            if [ `echo "$date2" | cut -c 6-7` -eq `echo "$date1" | cut -c 6-7` ] ; then
                if [ `echo "$date2" | cut -c 9-10` -lt `echo "$date1" | cut -c 9-10` ] ; then
                    echo 'the second date need to be higher than the first one'
                    exit 16
                fi
            fi
        fi
        bool3=2
        bool2=2
    fi
    if [ $bool1 -eq 1 ] ; then
        date1="$qu"
	    if [ "${#qu}" -ne 10 ] ; then 
            echo "'Write the date in the format YYYY-MM-DD after the -d'"
            exit 17
	    fi
        if [ `echo "$date1" | cut -c 5` != '-' ] || [ `echo "$date1" | cut -c 8` != '-' ] ; then
            echo 'Write the date in the format YYYY-MM-DD after the -d'
            exit 18
        fi
        if [ `echo "$date1" | cut -c -4` -gt 2022 ] || [ `echo "$date1" | cut -c -4` -lt 2010 ] ; then
            echo 'Write a year between 2010 and 2022'
            exit 19
        fi
        if [ `echo "$date1" | cut -c 6-7` -gt 12 ] || [ `echo "$date1" | cut -c 6-7` -lt 1 ] ; then
            echo 'Write a mount between 1 and 12'
            exit 20
        fi
        if [ `echo "$date1" | cut -c 9-10` -gt 31 ] || [ `echo "$date1" | cut -c 9-10` -lt 1 ] ; then
            echo 'Write a day between 1 and 31'
            exit 21
        fi
        if [ `echo "$date1" | cut -c 6-7` = 2 ] || [ `echo "$date1" | cut -c 6-7` = 4 ] || [ `echo "$date1" | cut -c 6-7` = 6 ] || [ `echo "$date1" | cut -c 6-7` = 8 ] || [ `echo "$date1" | cut -c 6-7` = 10 ] || [ `echo "$date1" | cut -c 6-7` = 12 ] && [ `echo "$date1" | cut -c -4` -gt 30 ] ; then
            echo 'No more than 30 days for these mounths!'
            exit 22
        fi
        if [ $(( `echo "$date1" | cut -c -4` % 4 )) = 0 ] ; then
            if [ `echo "$date1" | cut -c 6-7` = 2 ] && [ `echo "$date1" | cut -c 9-10` -gt 29 ] ; then
                echo 'Write a day between 1 and 29 for this mounth'
                exit 23
            fi
        else
            if [ `echo "$date1" | cut -c 6-7` = 2 ] && [ `echo "$date1" | cut -c 9-10` -gt 28 ] ; then
                echo 'Write a day between 1 and 28 for this mounth'
                exit 24
            fi
        fi
        bool2=1
        bool1=2
    fi
    if [ ${qu} = '-d' ] && [ $bool1 -eq 0 ] ; then
        bool1=1
    fi
done

#If there is only one of the three arguments needed, return an error.
if [ "$bool1" -ne "$bool2" ] || [ "$bool2" -ne "$bool3" ] || [ "$bool1" -ne "$bool3" ] ; then
    echo 'error on the date, it probably misses something'
    exit 25
fi


#We search the --avl, --abr or the --tab argument.
#If they are too much of them, return an error.
bool1=0
argtri='_'
for qu in $* ; do
    if [ "${qu}" = '--tab' ] || [ "${qu}" = '--avl' ] || [ "${qu}" = '--abr' ] ; then
        if [ $bool1 -eq 0 ] ; then
            bool1=1
            argtri="$qu"
        else
            echo 'There are too much arguments for the type of sorting'
            exit 26
        fi
    fi
done


#We search the option arguments.
#Return an error if none of them, or too much of them.
donneet1=' '
donneet2=' '
donneet3=' '
donneep1=' '
donneep2=' '
donneep3=' '
donneew=' '
donneeh=' '
donneem=' '
    
for qu in $* ; do

    if [ "${qu}" = '-t1' ] && [ ! "$donneet1" = '-t1' ] ; then
        donneet1="$qu"
    elif [ "${qu}" = '-t1' ] && [ "$donneet1" = '-t1' ] ; then
        echo "there are too much -t1 argument"
        exit 27
    fi
    if [ "${qu}" = '-t2' ] && [ ! "$donneet2" = '-t2' ] ; then
        donneet2="$qu"
    elif [ "${qu}" = '-t2' ] && [ "$donneet2" = '-t2' ] ; then
        echo "there are too much -t2 argument"
        exit 28
    fi
    if [ "${qu}" = '-t3' ] && [ ! "$donneet3" = '-t3' ] ; then
        donneet3="$qu"
    elif [ "${qu}" = '-t3' ] && [ "$donneet3" = '-t3' ] ; then
        echo "there are too much -t3 argument"
        exit 29
    fi
    if [ "${qu}" = '-p1' ] && [ ! "$donneep1" = '-p1' ] ; then
        donneep1="$qu"
    elif [ "${qu}" = '-p1' ] && [ "$donneep1" = '-p1' ] ; then
        echo "there are too much -p1 argument"
        exit 30
    fi
    if [ "${qu}" = '-p2' ] && [ ! "$donneep2" = '-p2' ] ; then
        donneep2="$qu"
    elif [ "${qu}" = '-p2' ] && [ "$donneep2" = '-p2' ] ; then
        echo "there are too much -p2 argument"
        exit 31
    fi
    if [ "${qu}" = '-p3' ] && [ ! "$donneep3" = '-p3' ] ; then
        donneep3="$qu"
    elif [ "${qu}" = '-p3' ] && [ "$donneep3" = '-p3' ] ; then
        echo "there are too much -p3 argument"
        exit 32
    fi
    if [ "${qu}" = '-w' ] && [ ! "$donneew" = '-w' ] ; then
        donneew="$qu"
    elif [ "${qu}" = '-w' ] && [ "$donneew" = '-w' ] ; then
        echo "there are too much -w argument"
        exit 33
    fi
    if [ "${qu}" = '-h' ] && [ ! "$donneeh" = '-h' ] ; then
        donneeh="$qu"
    elif [ "${qu}" = '-h' ] && [ "$donneeh" = '-h' ] ; then
        echo "there are too much -h argument"
        exit 34
    fi
    if [ "${qu}" = '-m' ] && [ ! "$donneem" = '-m' ] ; then
        donneem="$qu"
    elif [ "${qu}" = '-m' ] && [ "$donneem" = '-m' ] ; then
        echo "there are too much -m argument"
        exit 35
    fi


done

#We verify the presence of at least one option argument.
if [ "$donneet1" = ' ' ] && [ "$donneet2" = ' ' ] && [ "$donneet3" = ' ' ] && [ "$donneep1" = ' ' ] && [ "$donneep2" = ' ' ] && [ "$donneep3" = ' ' ] && [ "$donneew" = ' ' ] && [ "$donneeh" = ' ' ] && [ "$donneem" = ' ' ] ; then
    echo 'You need to enter an argument about the type of data you want to analyse'
    exit 36
fi

#Clean what is not needed.
make clean
if [ "$?" -ne 0 ] ; then
    echo "There was an error during the process of the cleaning of the files."
    exit 38
fi

#Compile at your place.
make
if [ "$?" -ne 0 ] ; then
    echo "There was an error during the process of the Makefile. Maybe a data-sorting file is missing."
    exit 38
fi

#Create the folder needed for storing the temporary files.
make Meteotmpfiles

if [ "$?" -ne 0 ] ; then
    echo "There was an error during the process of the creation of the temporary files folder."
    exit 38
fi

#We filter by date and create a 'firstfile'. If there is no date, just move it to 'firstdate'
if [ ! "$date1" = ' ' ] && [ ! "$date2" = ' ' ] ; then
    cat "$namefile" | sed '1d' | tr 'T' ';' | awk -F ';' '{if($2>="'$date1'" && $2<"'$date2'")print $0;}' > ./Meteotmpfilesfolder/firstfile
else
    cat "$namefile" | sed '1d' | tr 'T' ';' > ./Meteotmpfilesfolder/firstfile
fi

#We filter by region and create a 'secondfile'. If there is no region specified, just move it to 'secondfile'.
case $region in
' ')
cat ./Meteotmpfilesfolder/firstfile | awk -F";" '{sub(",",";",$11);print}' OFS=";" > ./Meteotmpfilesfolder/secondfile
;;
'-F')
cat ./Meteotmpfilesfolder/firstfile | awk -F ';' '{if($1 >= 7005 && $1 <= 7790) print $0}' | awk -F";" '{sub(",",";",$11);print}' OFS=";" > ./Meteotmpfilesfolder/secondfile
;;
'-G')
cat ./Meteotmpfilesfolder/firstfile | awk -F ';' '{if($1 >= 81401 && $1 <= 81415) print $0}' | awk -F";" '{sub(",",";",$11);print}' OFS=";" > ./Meteotmpfilesfolder/secondfile
;;
'-S')
cat ./Meteotmpfilesfolder/firstfile | awk -F ';' '{if($1 == 71805) print $0}' | awk -F";" '{sub(",",";",$11);print}' OFS=";" > ./Meteotmpfilesfolder/secondfile
;;
'-A')
cat ./Meteotmpfilesfolder/firstfile | awk -F ';' '{if($1 >= 78890 && $1 <= 78925) print $0}' | awk -F";" '{sub(",",";",$11);print}' OFS=";"> ./Meteotmpfilesfolder/secondfile
;;
'-O')
cat ./Meteotmpfilesfolder/firstfile | awk -F ';' '{if($1 >= 61968 && $1 <= 67005) print $0}'| awk -F";" '{sub(",",";",$11);print}' OFS=";"> ./Meteotmpfilesfolder/secondfile
;;
'-Q')
cat ./Meteotmpfilesfolder/firstfile | awk -F ';' '{if($1 == 89642) print $0}'| awk -F";" '{sub(",",";",$11);print}' OFS=";"> ./Meteotmpfilesfolder/secondfile
;;
esac


#Here, we filter the data by using precedent arguments stored.
#At this stage is stored : namefile - region - date1/date2 - donneet1 - donneet2 - donneet3 - donneep1 - donneep2 - donneep3 - donneew - donneeh - donneem 
if [ ! "$donneet1" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatat1' "$argtri" -nr
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c barre_erreurt1
        rm -f ./Meteotmpfilesfolder/ordereddatat1
    fi
fi

if [ ! "$donneet2" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatat2' "$argtri" -nr
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c ligne_simplet2
        rm -f ./Meteotmpfilesfolder/ordereddatat2
    fi
fi

#Unreleased part.
#if [ ! "$donneet3" = ' ' ] ; then
#    touch ./Meteotmpfilesfolder/filtereddatat3
#    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatat3' "$argtri" -nr
#    if [ "$?" -ne 0 ] ; then
#        echo "There was an error during the process of the sorting "
#        make clean
#        exit 38
#    fi
#fi

if [ ! "$donneep1" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatap1' "$argtri" -nr
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c barre_erreurp1
        rm -f ./Meteotmpfilesfolder/ordereddatap1
    fi
fi

if [ ! "$donneep2" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatap2' "$argtri" -nr
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c ligne_simplep2
        rm -f ./Meteotmpfilesfolder/ordereddatap2
    fi
fi

#Unreleased part.
#if [ ! "$donneep3" = ' ' ] ; then
#    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatap3' "$argtri" -nr
#    if [ "$?" -ne 0 ] ; then
#        echo "There was an error during the process of the sorting "
#        make clean
#        exit 38
#    fi
#fi

if [ ! "$donneew" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddataw' "$argtri" -r
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c vectors_w
        rm -f ./Meteotmpfilesfolder/ordereddataw
    fi
fi

if [ ! "$donneeh" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatah' "$argtri" -r
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c interpolee_alt
        rm -f ./Meteotmpfilesfolder/ordereddatah
    fi
fi

if [ ! "$donneem" = ' ' ] ; then
    ./execmeteotri -f './Meteotmpfilesfolder/secondfile' -o './Meteotmpfilesfolder/ordereddatam' "$argtri" -r
    if [ "$?" -ne 0 ] ; then
        echo "There was an error during the process of the sorting "
        make clean
        exit 38
    else
        gnuplot -p -c interpolee_m
        #rm -f ./Meteotmpfilesfolder/ordereddatam
    fi
fi

echo 'The programm is finished.'
#make clean













