#! /bin/bash

if [ -z "$2" ] || [ "$1" == "help" ]
  then
    echo "Parameters are [USER] [Build Folder Path] [Modifier 1] [Modifier 2] [DEL Logs]"
    echo "[USER] - FIT Username to be SSH'd into Andrew"
    echo "[Build Folder Path] - path to build folder (don't forget last slash)"
    echo "[Modifier 1] - Gallagher Prog modifier 1 *OPTIONAL*"
    echo "[Modifier 2] - Gallagher Prog modifier 2 *OPTIONAL*"
    echo "[DEL Logs] - Use value DEL to delete previous logs *OPTIONAL*"
    exit 1
fi



USER=$1
LOC=$2
TESTSITE=$USER@cs-scompute.cs.fit.edu
TESTPATH=~kgallagher/public_html/sampleprogs/
ORACLEPATH=~kgallagher/public_html/oracles/
DATE=`date '+%Y-%m-%d_%H:%M:%S'`
LOGNAME=$DATE.log
ERRORNAME=$DATE.err
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

if [ "$5" == "DEL" ]
  then
    echo "Delete Logs"
    [ -e log.log ] && rm $LOGNAME
    [ -e error.log ] && rm $ERRORNAME
fi

for ((II=0; II < ${#GENERATORS[@]}; ++II)) do

  echo $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4 >> $LOGNAME
  echo "" >> $LOGNAME   #Clean Output
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4 >> $LOGNAME
  echo "" >> $LOGNAME

  #Pipe to my program
  echo "Output for Tested Prog: ${MYPROGS[II]}" >> $LOGNAME
  echo "" >> $LOGNAME
  echo "Time and Errors for Tested Prog: ${MYPROGS[II]}" >> $ERRORNAME
  echo "" >> $ERRORNAME
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4  | /usr/bin/time --verbose $LOC${MYPROGS[II]} >> $LOGNAME 2>>$ERRORNAME
  echo "" >> $LOGNAME
  echo "" >> $ERRORNAME

  #Pipe to his Oracle
  echo "Output for Oracle: ${TARGETS[II]}" >> $LOGNAME
  echo "" >> $LOGNAME
  echo "Time and Errors for Oracle: ${TARGETS[II]}" >> $ERRORNAME
  echo "" >> $ERRORNAME
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4  | /usr/bin/time --verbose  ssh $TESTSITE $ORACLEPATH${TARGETS[II]} >> $LOGNAME 2>>$ERRORNAME
  echo "" >> $LOGNAME
  echo "" >> $ERRORNAME


done
