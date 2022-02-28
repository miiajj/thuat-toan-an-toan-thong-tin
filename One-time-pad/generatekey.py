import math, random

def genKey(length):
	alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
	result = ""
	for i in range(length):
		result += alphabet[math.floor(random.randint(0, 25))]
	return result