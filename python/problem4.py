#!/usr/bin/python

# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
# Find the largest palindrome made from the product of two 3-digit numbers.

def reverse(n):
	reversed = 0
	while n > 0:
		reversed = 10*reversed + n % 10
		n = n/10

	return reversed

def is_palindrome(n):
	return n == reverse(n)

# Consider the digits of P: let them be x, y and z. 
# P must be at least 6 digits long since the palindrome 111111 = 143 x 777 minus the product of two 3-digit integers. 
# Since P is palindromic:
# P=100000x+10000y+1000z+100z+10y+x
# P=100001x+10010y+1100z
# P=11(9091x+910y+100z)
# Since 11 is prime, at least one of the integers a or b must have a factor of 11.
# So if a is not divisible by 11 then we know b must be. Using this information
# we can determine what values of b we check depending on a.

def super_fast():
	largest_pali = 0
	a = 999
	b = 0
	db = 1

	while a >= 100:
		if a % 11 == 0:
			b = 999
			db = 1
		else:
			b = 990
			db = 11
		while b >= a:
			if a*b <= largest_pali:
				break

			if is_palindrome(a*b):
				largest_pali = a*b
			b = b - db
		a = a - 1

	return largest_pali

def solve():
	largest_pali = 0
	a = 999
	b = 0
	while a >= 100:
		b = 999
		while b >= a:
			if a*b <= largest_pali:
				break
			if is_palindrome(a*b):
				largest_pali = a*b
			b = b -1
		a = a - 1
	return largest_pali

print solve()
# print super_fast()


