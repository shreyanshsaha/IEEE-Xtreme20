# a simple parser for python. use get_number() and get_word() to read
import scipy
import numpy


def parser():
	while 1:
		data = list(input().split(' '))
		for number in data:
			if len(number) > 0:
				yield(number)


input_parser = parser()


def get_word():
	global input_parser
	return next(input_parser)


def get_number():
	data = get_word()
	try:
		return int(data)
	except ValueError:
		return float(data)


# numpy and scipy are available for use


def allClear(cards):
	for i in cards:
		if i != -1:
			return False
	return True

def zeroExists(cards):
	for i in cards:
		if i==0:
			return True
	return False

def getNotClear(cards, prevI):
	# get i
	if zeroExists(cards):
		for i in range(len(cards)):
			if cards[i] != -1 and i != prevI and cards[i]==0:
				break
	else:
		for i in range(len(cards)):
			if cards[i] != -1 and i != prevI:
				break

	# get j with value 0
	for j in range(len(cards)):
		if i != j and cards[j] != -1 and cards[j] == 0:
			break

	# Check if similar value of i exists
	for k in range(i, len(cards)):
		if k != i and k != j and cards[k] == cards[i]:
			# print("K Returned")
			return i, k

	return i, j


a = get_number()
n = 2*a
cards = [0 for i in range(n)]

i = 1

while(not allClear(cards)):
	# print(cards)
	i, j = getNotClear(cards, i)
	print(i+1, j+1)
	ans = input().rstrip()

	if ans == 'MATCH':
		cards[i] = -1
		cards[j] = -1
		continue
	else:
		cards[i] = int(ans.split(' ')[0])
		cards[j] = int(ans.split(' ')[1])
print(-1)
