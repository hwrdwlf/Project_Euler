#!/bin/usr/python

# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

import math


def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)/(2*i)+1)
    return [2] + [i for i in xrange(3,n,2) if sieve[i]]

# k = 20
# n = 1
# i = 1
# check = 1
# prime_list = primes(40)
# a = 0
# limit = math.sqrt( k )

# while prime_list[i] <= k:
# 	a = 1
# 	if check:
# 		if prime_list[i] <= limit:
# 			a = math.floor( math.log(k) / math.log(prime_list[i]) )
# 		else:
# 			check = 0
# 	n = n * math.pow( prime_list[i], a )
# 	i = i + 1

# print n
def gcd(a,b):
	if a < b:
		return gcd(b,a)
	if a % b == 0:
		return b
	else:
		return gcd(b, a%b)

def lcm(a,b):
	return abs(a*b)/gcd(a,b)

n = 20
print reduce(lambda res, x: lcm(res,x), range(n, 1, -1), 1)