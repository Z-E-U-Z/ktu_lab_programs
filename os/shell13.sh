#!/bin/bash

echo Enter a DAT file
read fdat1
echo Enter the new DAT file
read fdat2

echo `head -1 $fdat1 | cat > $fdat2` `grep -v NAME $fdat1 | sort -grk 3 | cat >> $fdat2`

# echo `head -1 $fdat1 | cat > $fdat2` `grep -v NAME $fdat1 | sort -t : -r -k 3 | cat >> $fdat2`
# If delimiter is ":"

echo $fdat1 successfully sorted based on ROLL_NO and copied to $fdat2
