#! /bin/bash

if [ -z "$4" ] || [ "$1" == "help" ]
  then
    echo "Parameters are [USER] [Build Folder Path] [Modifier 1] [Modifier 2] [DEL Logs]"
    echo "[USER] - FIT Username to be SSH'd into Andrew"
    echo "[Build Folder Path] - path to build folder (don't forget last slash)"
    echo "[Modifier 1] - Gallagher Prog modifier 1"
    echo "[Modifier 2] - Gallagher Prog modifier 2"
    echo "[DEL Logs] - Use value DEL to delete previous logs"
    exit 1
fi

if [ "$5"=="DEL" ]
  then
    echo "Delete Logs"
    [ -e log.log ] && rm file
    [ -e error.log ] && rm file
fi



USER=$1
LOC=$2
TESTSITE=$USER@cs-scompute.cs.fit.edu
TESTPATH=~kgallagher/public_html/sampleprogs/
ORACLEPATH=~kgallagher/public_html/oracles/
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

for ((II=0; II < ${#GENERATORS[@]}; ++II)) do

  echo $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4 >> log.log
  echo "" >> log.log
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4 >> log.log
  echo "" >> log.log
  #Pipe to my program
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4  | /usr/bin/time --verbose $LOC${MYPROGS[II]} >> log.log 2>>error.log
  echo "" >> log.log
  echo "" >> error.log
  #Pipe to his Oracle
  ssh $TESTSITE $TESTPATH${GENERATORS[II]} $3 $4  | /usr/bin/time --verbose  ssh $TESTSITE $ORACLEPATH${TARGETS[II]} >> log.log 2>>error.log
  echo "" >> log.log
  echo "" >> error.log


done