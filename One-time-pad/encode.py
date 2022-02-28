def encode(plaintext, key):
	alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
	pText = []
	kText = []
	for i in range(len(plaintext)):
		pText.append(alphabet.index(plaintext[i]))
		kText.append(alphabet.index(key[i]))
	result = ""
	for i in range(len(pText)):
		result += alphabet[(pText[i] + kText[i]) % 26]
	return result;