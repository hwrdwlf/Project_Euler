'''
Problem 7, https://projecteuler.net/problem=7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
'''
import time
import math
import pprint


def is_prime(n):
	if n == 1:
		return 0
	elif n < 4: # 2 and 3 are prime
		return 1
	elif n % 2 == 0:
		return 0
	elif n < 9: # exclude 4,6,8
		return 1
	elif n % 3 == 0:
		return 0
	else: 
		r = math.floor( math.sqrt( n ) ) # sqrt(n) rounded to greatest integer r so that r*r <= n
		f = 5
		while f <= r:
			if n % f == 0:
				return 0
			if n % (f+2) == 0:
				return 0
			f = f + 6

	return 1

LIMIT = 10001
count = 1
c = 1
while count < LIMIT:
	c = c + 2
	if is_prime(c):
		count = count + 1

print c
