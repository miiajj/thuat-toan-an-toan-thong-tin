def decode(ciphertext, key):
	alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
	cText = []
	kText = []
	for i in range(len(ciphertext)):
		cText.append(alphabet.index(ciphertext[i]))
		kText.append(alphabet.index(key[i]))
	result = ""
	for i in range(len(cText)):
		op = (cText[i] - kText[i])
		if op < 0:
			x = 26 + op
		else:
			x = op % 26
		result += alphabet[x]
	return result;