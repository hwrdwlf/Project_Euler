'''
Problem 10, https://projecteuler.net/problem=10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
'''


limit = 2000000
sievebound = (limit - 1) / 2
crosslimit = int(math.sqrt(limit) - 1) / 2
sieve = [0] * sievebound

for i in range(1, crosslimit):
	if sieve[i] == 0:
		for j in range(2*i*(i+1), sievebound, 2*i+1):
			sieve[j] = 1

sum = 2
for i in range(1, sievebound):
	if sieve[i] == 0:
		sum = sum + (2*i+1)
print sum






















