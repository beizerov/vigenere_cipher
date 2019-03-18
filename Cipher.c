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
    if (text != NULL)
    {  
        // Buffer for chars
        string buffer = malloc(strlen(text) + 1);

        if (buffer == NULL) {
            return NULL;
        }

        int buffer_index = 0;
        // key_c is variable for ASCII character in integer value 
        int key_c = 0;

        // Changes characters of the original text into cipher
        for (int i = 0, j = 0, n = strlen(text); i < n; i++)
        {   
            if (isalpha(text[i]))
            {
                // Each character of the keyword is applied to each text character
                for (int keyLength = strlen(key); ;)
                {   
                    if (j == keyLength)
                    {
                        j = 0;
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
                    
                    j++;
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
                // For an uppercase letter 
                if (isupper(text[i]) && (text[i] + key_c) > 'Z')
                {
                     buffer[buffer_index++] =  text[i] + key_c - 26;
                }
                // For an lowercase letter
                else if (islower(text[i]) && (text[i] + key_c) > 'z')
                {
                     buffer[buffer_index++] = text[i] + key_c - 26;
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
