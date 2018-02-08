# Assignment 2

From the in-class discussion, we will be making a bash script that compares my results to the results of an oracle.

## Structure
Assignment 2 is similar to Assignment 1 in layout. Using ./compile.sh, each test will be compiled into a build folder. Then two different test scripts can be used: location_agnostic.sh and location_speficic.sh.

## location_agnostic.sh

Location Agnostic expects the user to feed it the location of the build folder. This allows the script to be run from anywhere, and is thus location agnostic.

### Parameters
Parameters            | Description
--------------------- | ------------------------------------
\[USER\]              | FIT Username to be ssh'd into Andrew
\[Bulid Folder Path\] | Path to build folder (don't forget last slash)
\[Modifier 1\]        | Gallagher Program Modifier 1 \*Optional\*
\[Modifier 2\]        | Gallagher Program Modifier 2 \*Optional\*
\[DEL Logs\]          | Putting DEL will delete previous logs \*Optional\*

Example formatting:

```
./location_agnostic.sh rbomalaski2015 ~/git/swe5415/assignment_1/build/ 10 10 DEL
```

## location_specific.sh
Location Specific needs to be run from the scripts folder, as it uses internal logic to navigate to the build folder created by ./compile.sh. Since it needs to be in the correct spot, it is location specific.

### Parameters
Parameters            | Description
--------------------- | ------------------------------------
\[USER\]              | FIT Username to be ssh'd into Andrew
\[Modifier 1\]        | Gallagher Program Modifier 1 \*Optional\*
\[Modifier 2\]        | Gallagher Program Modifier 2 \*Optional\*
\[DEL Logs\]          | Putting DEL will delete previous logs \*Optional\*

Example formatting:

```
./location_specific.sh rbomalaski2015 10 10 DEL
```

## Output Format
Currently, both scripts will output to two files. One is an output log and the other is an error/testing output log. They are titled as date_time.log and date_time.err. They are created in the same directory that the script is run in.

## Bug List

## Version Control
Version Number | Description
-------------- | -----------
Version 1.0    | Uses Version 1.1 of Assignment 1, Initial Submission
