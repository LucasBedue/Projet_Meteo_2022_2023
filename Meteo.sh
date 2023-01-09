#!/bin/bash

#Programme regardant si les paramètres sont les bons, dicte au programme Meteocreationfichier.c
#quoi faire et envoie les information a afficher via gnuplot.
#On lit les parametres, on les retient, on regarde si ils sont correct et si oui, on fait le tri.


#on vérifie qu'il y a au moins un argument
if (( $# == 0 )) ; then
	echo 'You need arguments!'
	exit 1
fi


#regarde si il y a un --help au début
for qu in `echo "$*" | cut -d ' ' -f 1` ; do
	if [ ${qu} = '--help' ] ; then
		echo 'liste commande et parametre' #penser a ecrire ici!
		exit 4
	fi

done



#we search the -f <file> argument
bool1=0 #regarde si il y a le -f
bool2=0 #regarde si il y a le nom de fichier après
for qu in $* ; do 
	if [ $bool1 -eq 1 ] ; then
		if [ $bool2 -ne 1 ] ; then
			if [ -f ${qu} ] && [ -r ${qu} ] ; then
				bool2=1 #the file exist and is readable
				namefile="$qu"
			else
				echo 'There is no readable file after the -f'
				exit 2
			fi
		fi
	fi

	if [ ${qu} = '-f' ] && [ $bool1 -eq 0 ]; then
		bool1=1
	fi
done
if [ $bool1 -ne 1 ] && [ bool2 -ne 1 ] ; then
	echo 'There is no file in argument'
	exit 3
fi


#On regarde si il y a un parametre de région et le retient
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


#On regarde si il y a un parametre de date et le retient
date1=' '
date2=' '
bool1=0 #regarde si il n'y a qu'un -d
bool2=0 #regarde si ce qu'il y a après le -d est lisible
bool3=0 #regarde si ce qu'il y a deux crans après le -d est lisible
for qu in $* ; do
	if [ $bool2 -eq 1 ] ; then
		date2="$qu"
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
			exit 15
		fi
		if [ `echo "$date2" | cut -c -4` -eq `echo "$date1" | cut -c -4` ] ; then
			if [ `echo "$date2" | cut -c 6-7` -lt `echo "$date1" | cut -c 6-7` ] ; then
				echo 'the second date need to be higher than the first one'
				exit 16
			fi
		fi
		if [ `echo "$date2" | cut -c -4` -eq `echo "$date1" | cut -c -4` ] ; then
			if [ `echo "$date2" | cut -c 6-7` -eq `echo "$date1" | cut -c 6-7` ] ; then
				if [ `echo "$date2" | cut -c 9-10` -lt `echo "$date1" | cut -c 9-10` ] ; then
					echo 'the second date need to be higher than the first one'
					exit 17
				fi
			fi
		fi
		bool3=2
		bool2=2
	fi
	if [ $bool1 -eq 1 ] ; then
		date1="$qu"
		if [ `echo "$date1" | cut -c 5` != '-' ] || [ `echo "$date1" | cut -c 8` != '-' ] ; then
			echo 'Write the date in the format YYYY-MM-DD after the -d'
			exit 7
		fi
		if [ `echo "$date1" | cut -c -4` -gt 2022 ] || [ `echo "$date1" | cut -c -4` -lt 2010 ] ; then
			echo 'Write a year between 2010 and 2022'
			exit 8
		fi
		if [ `echo "$date1" | cut -c 6-7` -gt 12 ] || [ `echo "$date1" | cut -c 6-7` -lt 1 ] ; then
			echo 'Write a mount between 1 and 12'
			exit 9
		fi
		if [ `echo "$date1" | cut -c 9-10` -gt 31 ] || [ `echo "$date1" | cut -c 9-10` -lt 1 ] ; then
			echo 'Write a day between 1 and 31'
			exit 10
		fi
		if [ `echo "$date1" | cut -c 6-7` = 2 ] || [ `echo "$date1" | cut -c 6-7` = 4 ] || [ `echo "$date1" | cut -c 6-7` = 6 ] || [ `echo "$date1" | cut -c 6-7` = 8 ] || [ `echo "$date1" | cut -c 6-7` = 10 ] || [ `echo "$date1" | cut -c 6-7` = 12 ] && [ `echo "$date1" | cut -c -4` -gt 30 ] ; then
			echo 'No more than 30 days for these mounths!'
			exit 11
		fi
		if [ $(( `echo "$date1" | cut -c -4` % 4 )) = 0 ] ; then
			if [ `echo "$date1" | cut -c 6-7` = 2 ] && [ `echo "$date1" | cut -c 9-10` -gt 29 ] ; then
				echo 'Write a day between 1 and 29 for this mounth'
				exit 12
			fi
		else
			if [ `echo "$date1" | cut -c 6-7` = 2 ] && [ `echo "$date1" | cut -c 9-10` -gt 28 ] ; then
				echo 'Write a day between 1 and 28 for this mounth'
				exit 13
			fi
		fi
		bool2=1
		bool1=2
	fi
	if [ ${qu} = '-d' ] && [ $bool1 -eq 0 ] ; then
		bool1=1
	fi
done


if [ $bool1 -ne $bool2 ] || [ $bool2 -ne $bool3 ] || [ $bool1 -ne $bool3 ] ; then
	echo 'error on the date, it probably misses something'
	exit 14
fi


#On regarde si il y a un parametre de méthode de tri et le retient
bool1=0
argtri=' '
for qu in $* ; do
	if [ ${qu} = '--tab' ] || [ ${qu} = '--avl' ] || [ ${qu} = '--abr' ] ; then
		if [ $bool1 -eq 0 ] ; then
			bool1=1
			argtri="$qu"
		else
			echo 'There are too much arguments for the type of sorting'
			exit 15
		fi
	fi
done


#On regarde si il y a les paramêtre de tri, on tri tout en parcourant

donneet1=' '
ardonneet1=' '
donneet2=' '
ardonneet2=' '
donneet3=' '
ardonneet3=' '
doonnep1=' '
ardonneep1=' '
doonnep2=' '
ardonneep2=' '
doonnep3=' '
ardonneep3=' '
donneew=' '
donneeh=' '
donneem=' '
boolt=0 #Look if there is at least one argument of this kind entered
boolp=0
numargdonneet=0
numargdonneep=0

for qu in $* ; do
	if [ ${qu} = '-t' ] ; then
		if [ $boolt = 0 ] ; then
			
		elif [ $boolt = 1 ]

		elif [ $boolt = 2 ]

		else
		
		
		fi
	
	fi
	if [ ${qu} = '-p' ] ; then
		if [ $boolp = 0 ] ; then
		
		elif [ $boolp = 1 ]

		elif [ $boolp = 2 ]

		else

	fi
	if [ ${qu} = '-w' ] ; then

	fi
	if [ ${qu} = '-h' ] ; then

	fi
	if [ ${qu} = '-m' ] ; then

	fi


done



















