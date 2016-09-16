import math
from fractions import gcd

def is_prime(n):
	if n == 1:
		return 0
	elif n < 4: # 2 and 3 are prime
		return 1
	elif n % 2 == 0:
		return 0
	elif n < 9: # exclude 4,6,8
		return 1
	elif n % 3 == 0:
		return 0
	else: 
		r = math.floor( math.sqrt( n ) ) # sqrt(n) rounded to greatest integer r so that r*r <= n
		f = 5
		while f <= r:
			if n % f == 0:
				return 0
			if n % (f+2) == 0:
				return 0
			f = f + 6

	return 1

# based on using sieves to determine primes values
# index of the array is the key and whether or not it is prime is based on value
# array[2] = 1
# array[3] = 1
# array[4] = 0
# etc
def get_primes(limit):
	sievebound = (limit - 1) / 2
	crosslimit = int(math.sqrt(limit) - 1) / 2
	sieve = [0] * sievebound

	for i in range(1, crosslimit):
		if sieve[i] == 0:
			for j in range(2*i*(i+1), sievebound, 2*i+1):
				sieve[j] = 1

	return sieve