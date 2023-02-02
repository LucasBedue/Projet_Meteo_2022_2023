# Projet_Meteo_2022_2023
This program allows to manage a file of given meteorological data, sorting it thanks to some parameter given by the user and to make a graph with these data.

How to use it:

you just have to enter the command with the desired parameters:
./Meteo.sh -f name_file

ALL ARGUMENT
Arguments and script options [DATA TYPE]: 

-h:			height for each station. 

-m:			maximum moisture for each station. 

-p<mode>		atmospheric pressure 

1:		produces at the output the minimum, maximum and average pressures per station in ascending order of station number 

2:		average pressures by date/time, sorted in chronological order. 

3: 

-t<mode>		temperature	 

1:		produces at the output the minimum, maximum and average temperatures per station in ascending order of station number 

2:		average temperatures by date/time, sorted in chronological order. 

3: 

-w:			produces the average wind direction and speed for each station. 

Arguments and script options [DATES]: 

-date min max:	The output data is in the date range [min...max] included. The format of the dates is a string of type YYYY-MM-DD (year-month-day). 

Arguments and script options [SORT]: 

--avl:			sorting performed using an AVL type structure. This is the default sort if no sort type is selected 

--abr: 

Arguments and script options [FILE]: 

-f name_file:		input file. This option is obligatory 

Arguments and script options [LOCATION]: 

-F:			Metropolitan France + Corsica 

-G:			French Guyana 

-S:			Saint-Pierre and Miquelon 

-A:			Antilles 

-O:			Indian Ocean 

-Q:			Antarctica 
  
For example the parameter -h which makes a graph with the height of the stations and -m for the max moisture
with the command : ./Meteo.sh -f name_file -h -m
