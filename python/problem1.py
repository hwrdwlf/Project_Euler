#!/bin/usr/python

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

