'''
Problem 13, https://projecteuler.net/problem=13

Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
See p13.txt for the number
'''

ans = 0;
number_file = open('p13.txt')
number_list = number_file.readlines()
for number in number_list:
	ans += int(number)

print str(ans)[:10]
# Sort of one liner?
print str(sum([int(x) for x in number_list]))[:10]