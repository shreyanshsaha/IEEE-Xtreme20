from math import floor, ceil

def checksub(s):
	# print("CHECK:", s)
	if len(s) == 1:
		return True
	else:
		if len(s)%2==0:
			left = s[:int(len(s)/2)]
			right = s[int(len(s)/2):]
			# print("Check even", left, right)
			if left<=right:
				return checksub(left) and checksub(right)
		else:
			# Check upper bound
			left = s[:ceil(len(s)/2)]
			right = s[ceil(len(s)/2):]
			# print("Check odd lower", left, right)
			lower = True
			if left <= right:
				lower = checksub(left) and checksub(right)
			else:
				lower=False
			# Check lower bound
			left = s[:floor(len(s)/2)]
			right = s[floor(len(s)/2):]
			# print("Check odd upper", left, right)
			upper = True
			if left <= right:
				upper = checksub(left) and checksub(right)
			else:
				upper=False
			# print("Vals", lower, upper)
			return lower or upper

n = int(input())
values = []
result = []
for i in range(n):
	values.append(input().rstrip())
	if checksub(values[i]):
		result.append(1)
	else:
		result.append(0)
	# print(result)
for i in result:
	print(i, end='')
# for i in range(n):

'''
BBBABB
[0]
AABAAB
[0, 1]
AABAA
[0, 1, 0]
BBABAB
[0, 1, 0, 0]
ABBBBA
[0, 1, 0, 0, 0]
'''
