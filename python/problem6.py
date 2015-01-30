#!/usr/bin/python
# The sum of the squares of the first ten natural numbers is,
#  1^2 + 2^2 + ... + 10^2 = 385
# The square of the sum of the first ten natural numbers is,
# (1 + 2 + ... + 10)^2 = 55^2 = 3025
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
#
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


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
