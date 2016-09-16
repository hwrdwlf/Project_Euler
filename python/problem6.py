'''
Problem 6, https://projecteuler.net/problem=6

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
'''

limit = 100 
sum = limit * (limit + 1) / 2
sum_sqr = (2 * limit + 1) * (limit + 1) * limit / 6
print sum*sum - sum_sqr