'''
Problem 9, https://projecteuler.net/problem=9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
'''
#!/usr/bin/python

import math
from fractions import gcd
import time

def sol1():
   s = 1000
   for a in range(3, (s-3)/3):
      for b in range(a+1, (s-1-a) / 2):
         c = s - a - b
         if c*c == a*a + b*b:
            print a*b*c

def sol2():
   s = 1000
   s2 = s / 2
   limit = int(math.sqrt(s2) - 1)
   for m in range(2, limit):
      if s2 % m == 0:
         sm = s2 / m
         while sm % 2 == 0:
            sm = sm / 2
         if m % 2 == 1:
            k = m + 2
         else:
            k = m + 1
         while k < 2*m and k <= sm:
            if sm % k == 0 and gcd(k,m) == 1:
               d = s2 / (k*m)
               n = k - m 
               a = d * (m * m - n * n)
               b = 2 * d * m * n 
               c = d * (m * m + n* n)
               print a*b*c
            k = k + 2


start = time.time()
sol1()
end = time.time()
print "Computation time: ", end - start

start = time.time()
sol2()
end = time.time()
print "Computation time: ", end - start