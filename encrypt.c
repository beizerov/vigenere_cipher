/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "vigenere_cipher.h"


static int shift(const char* const keyword);


/*
 *  This feature encrypts incoming text.
 * Accepts two parameters: a keyword and plaintext for encryption.
 * The function returns a pointer to the cipher text.
 */
string encrypt(const char* const keyword, char* const str)
{
    const int LETTER_COUNT = 26;
	
    if (str != NULL)
    {  
        int str_length = strlen(str);
        // Variable value_to_increase to store the value by which 
        // the value of the character is increased during encryption.
        int value_to_increase = 0;

        // Changes plaintext characters to encrypted
        for (int i = 0; i < str_length; i++)
        {   
            if (isalpha(str[i]))
            {   
                // Shift is used only if the character is an alphabet character.
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
 *  This function shifts to the next character in the keyword 
 * and return a value from 0 to 25, like from A to Z. 
 *
 * A == 0, Z == 25.
 * Letter case not have matter.
 */
static int shift(const char* const keyword)
{
    static int j = 0;

    if (keyword[j] == '\0')
    {
        j = 0;  // Set up the index into the beginning character of the keyword
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
