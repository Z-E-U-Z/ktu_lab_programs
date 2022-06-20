#!/bin/bash

read -p "Enter n = " n

#sum=0
#for (( i=1; i<=$n; i++ )) do
#    sum=`expr $sum + $i`
#done

if [ 0 -gt $n ]; then
    echo Enter a non-negative integer
    exit
fi

sum=`expr \( $n \* $n + $n \) / 2`

echo Sum of first $n integers = $sum
