#! /bin/bash

## Check input for necessary parameters.
## Does not check input for validity
if [ -z "$1" ] || [ "$1" == "help" ]
  then
    echo "Parameters are [USER] [Modifier 1] [Modifier 2] [DEL Logs]"
    echo "[USER] - FIT Username to be SSH'd into Andrew"
    echo "[Modifier 1] - Gallagher Prog modifier 1 *OPTIONAL*"
    echo "[Modifier 2] - Gallagher Prog modifier 2 *OPTIONAL*"
    echo "[DEL Logs] - Use value DEL to delete previous logs *OPTIONAL*"
    exit 1
fi


## Make the variables
SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
cd ../
LOC=`pwd -P`
LOC="$LOC/build/"
cd $SCRIPTPATH
USER=$1
TESTSITE=$USER@cs-scompute.cs.fit.edu
TESTPATH=~kgallagher/public_html/sampleprogs/
ORACLEPATH=~kgallagher/public_html/oracles/
DATE=`date '+%Y-%m-%d_%H:%M:%S'`
LOGNAME=$DATE.log
ERRORNAME=$DATE.err

## Lists need to be of same length and have indices correspond
## i.e. The first index for each one needs to match across (eq, eq, eq_test)
GENERATORS=(
            eq
            func
            onetoone
            onto
            reflex
            sym
            trans
            )
TARGETS=( 
            eq
            func
            onetoone
            onto
            reflex
            sym
            trans
         )

MYPROGS=(
            eq_test
            func_test
            onetoone_test
            onto_test
            ref_test
            sym_test
            trans_test
        )

## If DEL flag, delete logs with same name as this one's log
if [ "$4" == "DEL" ]
  then
    echo "Delete Logs"
    [ -e $LOGNAME ] && rm $LOGNAME
    [ -e $ERRORNAME ] && rm $ERRORNAME
fi


## For each item in the generator list do the following:
##      1. Print out the output of the Generator
##      2. Pipe Generator Output to my corresponding program
##      3. Pipe Generator Output to corresponding oracle
## Write any output to the run log
## Write errors and verbose information to err log
for ((II=0; II < ${#GENERATORS[@]}; ++II)) do

  echo $TESTSITE $TESTPATH${GENERATORS[II]} $2 $3 >> $LOGNAME
  echo "" >> $LOGNAME   #Clean Output
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $2 $3 >> $LOGNAME
  echo "" >> $LOGNAME

  #Pipe to my program
  echo "Output for Tested Prog: ${MYPROGS[II]}" >> $LOGNAME
  echo "" >> $LOGNAME
  echo "Time and Errors for Tested Prog: ${MYPROGS[II]}" >> $ERRORNAME
  echo "" >> $ERRORNAME
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $2 $3  | /usr/bin/time --verbose $LOC${MYPROGS[II]} >> $LOGNAME 2>>$ERRORNAME
  echo "" >> $LOGNAME
  echo "" >> $ERRORNAME

  #Pipe to his Oracle
  echo "Output for Oracle: ${TARGETS[II]}" >> $LOGNAME
  echo "" >> $LOGNAME
  echo "Time and Errors for Oracle: ${TARGETS[II]}" >> $ERRORNAME
  echo "" >> $ERRORNAME
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $2 $3  | /usr/bin/time --verbose  ssh $TESTSITE $ORACLEPATH${TARGETS[II]} >> $LOGNAME 2>>$ERRORNAME
  echo "" >> $LOGNAME
  echo "" >> $ERRORNAME


done

## Future Fix:
## Output for C files should be made to try and match his output exactly, that way the actual outputs can be compared directly, thus allowing for even further automation of testing.
