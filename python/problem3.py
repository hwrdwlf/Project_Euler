#!/bin/usr/python
# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?
import math

n = 600851475143
last_factor = 0
if n % 2 == 0:
	last_factor = 2
	n = n / 2
	while n % 2 == 0:
		n = n / 2
else:
	last_factor = 1

factor = 3
max_factor = math.sqrt(n)
while n > 1 and factor <= max_factor:
	if n % factor == 0:
		n = n / factor
		last_factor = factor
		while n % factor == 0:
			n = n / factor
		max_factor = math.sqrt( n )
	factor = factor + 2
if n == 1:
	print last_factor
else:
	print n

