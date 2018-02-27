#!/bin/bash
cd ..
mkdir build >> build.log 2>>build.log
cd ./src
gcc version1.c -o ../build/version1 
gcc symmetric_test.c -o ../build/sym_test
gcc reflexive_test.c -o ../build/ref_test
gcc transitive_test.c -o ../build/trans_test
gcc onto_test.c -o ../build/onto_test
gcc onetoone_test.c -o ../build/onetoone_test
gcc func_test.c -o ../build/func_test
gcc eq_test.c -o ../build/eq_test
