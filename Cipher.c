/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "Cipher.h"


/*
 * This function encrypts incoming text
 */
string Cipher(string key, string text)
{
    const int LETTER_COUNT = 26;
	
    if (text != NULL)
    {  
        // Buffer for chars
        string buffer = malloc(strlen(text) + 1);

        if (buffer == NULL) {
            return NULL;
        }

        int buffer_index = 0;
        // The key_c variable to store the value by which to increase
        // the symbol value.
        int key_c = 0;

        // Changes characters of the original text into cipher
        for (int i = 0, j = 0, n = strlen(text); i < n; i++)
        {   
            if (isalpha(text[i]))
            {
                // Get value for key_c
                for (int keyLength = strlen(key);;)
                {   
                    if (j == keyLength)
                    {
                        j = 0;  // Return to the first character of the keyword
                        continue;
                    }
                    else if (isupper(key[j]))
                    {
                        key_c = (key[j] - 65);
                    }
                    else if (islower(key[j]))
                    {
                        key_c = (key[j] - 97);
                    }
                    
                    j++;  // Next character of keyword.
                    break;
                }
            }
            // Checks whether a character is a number 
            if (isdigit(text[i]))
            {
                 buffer[buffer_index++] = text[i];
            }
            // Checks whether the character is a punctuation character
            else if (ispunct(text[i]))
            {
                 buffer[buffer_index++] = text[i];
            }
            // Checks whether the character is a space character
            else if (isspace(text[i]))
            {
                 buffer[buffer_index++] = text[i];
            }
            else
            {   
                if (isupper(text[i]) && (text[i] + key_c) > 'Z')
                {
                     buffer[buffer_index++] =  text[i] + key_c - LETTER_COUNT;
                }
                else if (islower(text[i]) && (text[i] + key_c) > 'z')
                {
                     buffer[buffer_index++] = text[i] + key_c - LETTER_COUNT;
                } 
                else
                {
                     buffer[buffer_index++] = text[i] + key_c;
                }
            }    
        }

      // terminate string
      buffer[buffer_index++] = '\0';

      free(text);
      
      return buffer;
    }

    return NULL;
}
