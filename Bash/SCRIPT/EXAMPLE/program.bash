#!/bin/bash

for each in $@; do
    echo $each
done

if [[ $9 != "" ]]; then
    echo "First $0; Second : $1; Third : $2; ....; Last (9) : $9"
    shift 3
    echo "First $0; Second : $1; Third : $2; ....; Last (9) : $9"
else
     echo "First $0; Second : $1; Third : $2; ...."
fi
