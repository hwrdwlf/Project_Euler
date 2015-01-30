def numberToWord(number):
	ones = ["zero", "one", "two", "three","four","five","six","seven","eight","nine","", "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"]
	tens = ["zero", "ten", "twenty", "thirty","forty","fifty","sixty","seventy","eighty","ninety"]

	if(number < 0):
		return "Error"
	elif (number == 1000):
		return "one thousand"
	elif(number >= 20):
		index = number / 10;
		tensNumber = tens[index]
		index = number % 10
		onesNumber = ones[index]
		if(number % 10 == 0):
			return tensNumber
		else:
			return tensNumber + " " + onesNumber
	else:
		if(number == 10):
				return tens[1]
		else:
			return ones[number]

numList = []
totalCount = 0
for i in range(1,6):
	totalCount = totalCount + len(numberToWord(i))

print "Total character count: ", totalCount