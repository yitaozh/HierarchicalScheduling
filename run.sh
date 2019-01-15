#!/usr/bin/env bash

for d in $(find config/ -maxdepth 1 -type d)
do
    echo ${d}
    IFS='/' read -ra NAMES <<< "${d}"
    echo ${NAMES[2]}
    cd ${d}
        for filename in ${d}:
        do
           python trace_gen/trace_generator.py "$filename" ${NAMES[2]}
        done
   cd ..
done