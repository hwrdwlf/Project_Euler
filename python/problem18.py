#!/usr/bin/python
#
# By starting at the top of the triangle below and moving to adjacent numbers on the row below, 
# the maximum total from top to bottom is 23.

#    3
#   7 4
#  2 4 6
# 8 5 9 3

# That is, 3 + 7 + 4 + 9 = 23.
# Find the maximum total for the input file


def read_input(filename):
  line = None
  line_numbers = []
  lines = 0
  with open(filename) as file:
    for line in file:
      lines+=1

  input_data = [[0 for x in range(lines)] for x in range(lines)] 
  j = 0
  with open(filename) as file:
    for line in file:
      line = line.strip()
      numList = line.split(" ")
      i = 0
      for num in numList:
        input_data[j][i] = int(num)
        i+=1
      j+=1
  return input_data

triangle = read_input('/Users/walla/Desktop/data.txt')
print triangle


lines = len(triangle)
largest_path = []
print lines
for i in range(0,lines):
  largest_path.append(triangle[lines-1][i])

i = lines-2
for i in range(i,-1,-1):
  print "i -> ", i
  j = 0
  for j in range(0,i+1):
    largest_path[j] = triangle[i][j] + int(max(int(largest_path[j]), int(largest_path[j+1])))

print largest_path