#!/usr/bin/python
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
