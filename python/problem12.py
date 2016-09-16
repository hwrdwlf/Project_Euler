'''
Problem 12, https://projecteuler.net/problem=12

What is the value of the first triangle number to have over five hundred divisors?
'''
import library as lib
import time

# get a list of primes
start = time.time()

p_limit = 2000
primes = []
for i in range(0, 2000):
	if lib.is_prime(i):
		primes.append(i)

limit = len(primes)
n = 3
dn = 2
count = 0

DIVISORS = 500
while count <= DIVISORS:
	n = n + 1
	n1 = n 
	if n1 % 2 == 0:
		n1 /= 2
	dn1 = 1

	for i in range(1, limit): 
		if primes[i] * primes[i] > n1:
			dn1 *= 2
			break

		exp = 1
		while n1 % primes[i] == 0:
			exp += 1
			n1 /= primes[i]

		if exp > 1:
			dn1 *= exp

		if n1 == 1:
			break
	count = dn * dn1
	dn = dn1

print n * (n-1) / 2

end = time.time()
print "Computation time: %fs" % (end - start)

