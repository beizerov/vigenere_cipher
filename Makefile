#
# Makefile
# 
# Cipher
#
#


cipher: Cipher.h Cipher.c GetString.c main.c
	clang -std=c11 -Wall -Werror GetString.c Cipher.c main.c -o cipher

clean:
	rm -f *.o a.out core cipher 
