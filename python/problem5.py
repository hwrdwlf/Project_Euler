#!/bin/usr/python

# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

from time import clock,time


def GCD(num1, num2):
	while num2 != 0:
		num1, num2 = num2, num1%num2
		return num1
def LCM(num1, num2):
	result = num1*num2/GCD(num1,num2)
	return result

start = time()
var1 = 2520
i = 1
while i < 21:
	if var1%i == 0:
		i = i+1
	else:
		var1=var1+10
		i=1
end = (time() - start)
print var1
print "Time elapsed:",end
