#!/usr/bin/python
# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
#
# a^2 + b^2 = c^2
# For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
#
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.
import math

def isWhole(x):
   if(x%1==0):
      return True
   else:
      return False

list = []
m = 1
n = 2
prod = 0
sum1 = 0

for a in range(3,800):
   for b in range(4,800):
      c = pow(a,2) + pow(b,2)
      c = pow(a,.5)
      sum1 = a+b+c

      if(a!=b):
         if(isWhole(sum1)):
            print sum1
            if sum1 == 1000:
               prod = a*b*c
               list.append(prod)
               break

print list
print a, b, c
