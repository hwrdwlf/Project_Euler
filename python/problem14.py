'''
Problem 14, https://projecteuler.net/problem=14

The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
'''
import time

def solve(limit):
	a = 0
	b = 0
	d = [0] * (limit+1)
	d[1] = 1

	# im including a submethod here because im lazy
	# limit here acts as a local "global"
	def rec(n):
		ans = 0
		if n == 1:
			return 1
		if n <= limit:
			if d[n] > 0:
				return d[n]
		ans = 1 + rec(n/2) if n%2==0 else 1 + rec(3*n+1)

		if n <= limit: 
			d[n] = ans

		return ans
	for n in xrange(1, limit):
		if rec(n) > b:
			b = rec(n)
			a = n 
	return a



start = time.time()
print solve(10**6)
end = time.time()
print "Computational time: %fs" % (end - start)