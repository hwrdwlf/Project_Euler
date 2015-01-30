#!/usr/bin/python
#
# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
#
# Find the sum of all the primes below two million.

import math

prime = []
for n in range(2,10):
   for m in range(2,n/2):
      if n%2 != 0:
         if n%m != 0:
            print "value: " , n
            print "value: " , m
            prime.append(n)


print list(set(prime))























