#
# Makefile
# 
# Cipher
#
#


cipher: cipher.h cipher.c GetString.c main.c
	clang -std=c11 -Wall -Werror GetString.c cipher.c main.c -o cipher

clean:
	rm -f *.o a.out core cipher 
