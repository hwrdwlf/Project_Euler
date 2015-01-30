#!/bin/usr/python
# 
# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.

c1 = 3
c2 = 5
randomVal = 0
def addNumbers(num):
	total = randomVal
	for i in range(0,num):
		if i % 3 == 0 or i % 5 == 0:
			total = total + i	
	return total

print "Sum of multiples less than 10:", addNumbers(10) 
print "Sum of multiples less than 1000:", addNumbers(1000)

