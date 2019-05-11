/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "vigenere_cipher.h"


static int shift(const char* const keyword);


/*
 *  This function encrypts incoming text.
 * Takes two parameters keyword and plaintext for encrypt.
 * Return a reference on ciphertext.
 */
string encrypt(const char* const keyword, char* const str)
{
    static const int LETTER_COUNT = 26;
	
    if (str != NULL)
    {  
        int str_length = strlen(str);
        // The value_to_increase variable to store the value by which to 
        // increase the character value when encrypting.
        int value_to_increase = 0;

        // Changes characters of the plaintext into ciphertext
        for (int i = 0; i < str_length; i++)
        {   
            if (isalpha(str[i]))
            {   
                // Shift is used, if only the symbol is a symbol of the alphabet
                value_to_increase = shift(keyword);

                if (isupper(str[i]) && (str[i] + value_to_increase) > 'Z')
                {
                     str[i] += value_to_increase - LETTER_COUNT;
                }
                else if (islower(str[i]) && (str[i] + value_to_increase) > 'z')
                {
                     str[i] += value_to_increase - LETTER_COUNT;
                } 
                else
                {
                     str[i] += value_to_increase;
                }
            }
        }
      
      return str;
    }

    return NULL;
}


/*
 *  This function shift to next character in keyword 
 * and return value from 0 to 25, like from A to Z. 
 *
 * A == 0, Z == 25.
 * Letter case not have matter.
 */
static int shift(const char* const keyword)
{
    static int j = 0;

    if (keyword[j] == '\0')
    {
        j = 0;  // Return to the first character of the keyword
    }    

    if (isupper(keyword[j]))
    {
        return keyword[j++] - 'A';
    }
    else
    {
        return keyword[j++] - 'a';
    }
}
