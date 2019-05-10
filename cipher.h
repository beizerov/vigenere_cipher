/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#ifndef CIPHER_H
#define CIPHER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

typedef char* string;

string GetString(void);
string cipher(string keyword, string plaintext);

#endif //CIPHER_H
