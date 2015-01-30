#!/bin/usr/python

# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
#
# What is the 10 001st prime number?

def isPrime(x):
	x = abs(int(x))
	if x < 2:
		return False
	if x == 2:
		return True
	if not x & 1:
		return False
	for i in range(3, int(x*0.5)+1, 2):
		if x % i == 0:
			return False
	return True	

count = i =  0
list = []
while count < 10001:
	if isPrime(i):
		list.append(i)
		count+=1
		i+=1
	else:
		i+= 1

print list
