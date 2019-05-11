#
# Makefile
# 
# Cipher
#
#


vigenere: vigenere_cipher.h encrypt.c GetString.c main.c
	clang -std=c11 -Wall -Werror GetString.c encrypt.c main.c -o vigenere

clean:
	rm -f *.o a.out core vigenere
