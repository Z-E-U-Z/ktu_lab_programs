#!/bin/bash

if [ $# != 3 ]; then
    echo Too few arguments
    exit
fi
`head $1 | cat > $3`
`head $2 | cat >> $3`
echo Successfully copied first 10 lines from $1 and $2 to $3
