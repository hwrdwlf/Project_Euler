#!/bin/usr/python

def fib(num):
	total = 0
	t0 = 0
	newSum  = 0
	t1 = 1
	for i in range(0,num):
		total = t1 + t0
		t0 = t1
		t1 = total
		if(total%2 == 0 and total < 4000000):
			newSum = newSum + total
		if(total > 4000000):
			print "over 4 mil"
	return newSum

sum1 = 0
for x in range(0,4000000):
	sum1 = x + sum1
print "ans:", sum1
print "ans", fib(10)
print "ans", fib(40)
