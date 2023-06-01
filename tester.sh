#!/bin/bash
if [ ! -f "push_swap" ]
then
	make
fi

echo "How many numbers would you like to test?"
read cap
while [ -z "$cap" ]
do
	echo -e "\033[0;33mYou must define an amount of numbers to test.\033[0m"
	read cap
done
if [ $cap -lt 1 ]
then
	echo -e "\033[0;31mError: You must generate at least 1 number.\033[0m"
	exit 0
fi

echo "What is the highest number you would like to test?(INT_MAX: 2147483647)"
read max
while [ -z "$max" ]
do
	echo -e "\033[0;33mYou must define the highest number.\033[0m"
	read max
done
# Check that max is lower than INT_MAX
if [ $max -gt 2147483647 ]
then
	echo -e "\033[0;31mError: 2147483647 is INT_MAX\033[0m"
	exit 0
fi

echo "What is the lowest number you would like to test?(INT_MIN: -2147483648)"
read min
while [ -z "$min" ]
do
	echo -e "\033[0;33mYou must define the lowest number number.\033[0m"
	read min
done
if [ $min -lt -2147483648 ]
then
	echo -e "\033[0;31mError: -2147483648 is INT_MIN\033[0m"
	exit 0
# Check that min is lower than max
elif [ $min -gt $max ]
then
	echo -e "\033[0;31mError: Min can't be greater than max.\033[0m"
	exit 0
# Check that $cap is lower than the amount of numbers generated
elif [ $(($max - $min)) -lt $(($cap - 1)) ]
then
	echo -e "\033[0;31mError: Max - Min can't be lower than the range of numbers tested.\033[0m"
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
echo "Testing './push_swap' with the $cap random generated numbers..."
echo "./push_swap \$nums | ./checker_linux \$nums"$'\n'
echo "Result:"
chmod 777 checker_linux

result=`./push_swap $nums | ./checker_linux $nums`
if [ $result = "OK" ]
then
echo -e "\033[0;32mOK\033[0m" 
else
echo -e "\033[0;31mKO\033[0m"
fi

echo $'\n'"Number of operations:"
./push_swap $nums | wc -l

make fclean