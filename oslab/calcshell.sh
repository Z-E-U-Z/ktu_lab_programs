#!/bin/bash

echo
echo "Welcome to Scientific Calculator"
echo
echo "Operations"
echo "Addition: +"
echo "Subtraction: -"
echo "Multiplication: *"
echo "Division: /"
echo "Modulus: %"
echo "Exponential: ^"
echo "Parantheses: ()"
echo
echo "Enter expression: "
read exp
echo
echo "Answer: `awk "BEGIN{print $exp}"`"
echo
