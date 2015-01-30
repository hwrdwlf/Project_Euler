#!/usr/bin/python



def sumOfSquares(num):
	total = 0
	for i in range(1,num+1):
		temp = i**2;
		total = total + temp
	return total

def squareOfSums(num):
	total = 0
	for i in range(1,num+1):
		total = i + total
	square = total**2
	return square

print "Sum of Squares:", sumOfSquares(10)
print "Square of Sums:", squareOfSums(10)
print "Answer:", squareOfSums(100)-sumOfSquares(100)
