#!/usr/bin/python

# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

# Find the largest palindrome made from the product of two 3-digit numbers.

def checkPalindrome(num):
	string = str(num)
	if string == string[::-1]:
		return True
	else:
		return False


list = []
total = 0
for a in range(1,1000):
	for b in range(1,1000):
		total = b * a
		if checkPalindrome(total):
			list.append(total)
def reverseNum(x,y):
	return y - x

test = sorted(list, cmp = reverseNum)
print "ans:", test[0]

