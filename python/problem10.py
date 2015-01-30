#!/usr/bin/python
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























