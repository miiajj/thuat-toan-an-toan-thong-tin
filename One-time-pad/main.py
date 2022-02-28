import encode as enc
import decode as dec
import generatekey as gen
import re

print('Plaintext: ',end='')
inputPlaintext = input()
inputPlaintext = re.sub(r'\s+','',inputPlaintext).upper()
print('Uppercase and delete space : ' + inputPlaintext)

key = gen.genKey(len(inputPlaintext))
print('Key: ',key)

ciphertext = enc.encode(inputPlaintext,key)
print('Ciphertext: ' + ciphertext)
print('Decoding using the same key: ' + dec.decode(ciphertext, key))