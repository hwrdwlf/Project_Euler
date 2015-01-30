#!/bin/usr/python

def isPrime(x):
	x = abs(int(x))
	if x < 2:
		return False
	if x == 2:
		return True
	if not x & 1:
		return False
	for i in range(3, int(x*0.5)+1, 2):
		if x % i == 0:
			return False
	return True	

def primeFactor(i):
	factors = []
	while True:
		j = 2
		while j < i + 1:
			if i%j == 0 and isPrime(j):
				i = i / j
				factors.append(j)
				break
			j+=1
		if i == 1:
			break
	return factors

print "ans:", primeFactor(2009)
print "ans:", primeFactor(600851475143)
