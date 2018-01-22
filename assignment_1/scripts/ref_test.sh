#! /bin/bash
if [ -z "$1" ]
  then
    echo "No function specified"
    exit 1
fi

FUNC1=$1

cd ../build
ssh rbomalaski2015@cs-scompute.cs.fit.edu ~kgallagher/public_html/sampleprogs/$FUNC1 10 10 | ./ref_test