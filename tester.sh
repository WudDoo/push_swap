#!/bin/bash

echo "How many numbers would you like to test?"
read cap
if [ -z "$cap" ]
then
	echo "You must define a number"
	exit 0
elif [ $cap -lt 1 ]
then
	echo "You must generate at least 1 number"
	exit 0
fi

echo "What is the highest number you would like to test? Leave blank for $cap. (INT_MAX: 2147483647)"
read max
if [ -z "$max" ]
then
	max=$cap
# Check that max is lower than INT_MAX
elif [ $max -gt 2147483647 ]
then
	echo "2147483647 is the max"
	exit 0
fi

echo "What is the lowest number you would like to test? Leave blank for 1. (INT_MIN: -2147483648)"
read min
if [ -z "$min" ]
then
	min=1
# Check that min is greater than INT_MIN
elif [ $min -lt -2147483648 ]
then
	echo "-2147483648 is the min"
	exit 0
# Check that min is lower than max
elif [ $min -gt $max ]
then
	echo "Min can't be greater than max"
	exit 0
# Check that $cap is lower than the amount of numbers generated
elif [ $(($max - $min)) -lt $(($cap - 1)) ]
then
	echo "Max - Min can't be lower than the range of numbers tested."
	exit 0
fi


if [ $min -lt 0 ]
then
	echo "Generating $cap random numbers with zero/negatives..."
	nums=$(seq $min $max | shuf -n $cap | tr '\n' ' ')
else
	echo "Generating $cap random numbers without negatives..."
	nums=$(shuf -i $min-$max -n $cap | tr '\n' ' ')
fi

echo $'\n'"numbers generated: "$'\n'"{ $nums}"$'\n'
echo "Testing './push_swap' with $cap random numbers..."
echo "./push_swap \$nums | ./checker_linux \$nums"$'\n'
echo "Result:"
./push_swap $nums | ./checker_linux $nums
echo $'\n'"Number of operations:"
./push_swap $nums | wc -l
