/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "Cipher.h"


/*
 * This function encrypts incoming text
 */
string Cipher(string keyword, string text)
{
    const int LETTER_COUNT = 26;
	
    if (text != NULL)
    {  
        string ciphertext = malloc(strlen(text) + 1);

        if (ciphertext == NULL) {
            return NULL;
        }

        int ciphertext_index = 0;
        // The value_to_increase variable to store the value by which to 
        // increase the character value when encrypting.
        int value_to_increase = 0;

        // Changes characters of the original text into ciphertext
        for (int i = 0, j = 0, n = strlen(text); i < n; i++)
        {   
            if (isalpha(text[i]))
            {
                // Get value for value_to_increase
                for (int keyLength = strlen(keyword);;)
                {   
                    if (j == keyLength)
                    {
                        j = 0;  // Return to the first character of the keyword
                        continue;
                    }
                    else if (isupper(keyword[j]))
                    {
                        value_to_increase = (keyword[j] - 65);
                    }
                    else if (islower(keyword[j]))
                    {
                        value_to_increase = (keyword[j] - 97);
                    }
                    
                    j++;  // Next character of keyword.
                    break;
                }
            }
            // Checks whether a character is a number 
            if (isdigit(text[i]))
            {
                 ciphertext[ciphertext_index++] = text[i];
            }
            // Checks whether the character is a punctuation character
            else if (ispunct(text[i]))
            {
                 ciphertext[ciphertext_index++] = text[i];
            }
            // Checks whether the character is a space character
            else if (isspace(text[i]))
            {
                 ciphertext[ciphertext_index++] = text[i];
            }
            else
            {   
                if (isupper(text[i]) && (text[i] + value_to_increase) > 'Z')
                {
                     ciphertext[ciphertext_index++] =  text[i] 
                            + value_to_increase - LETTER_COUNT;
                }
                else if (
                         islower(text[i]) && (text[i] + value_to_increase) > 'z'
                )
                {
                     ciphertext[ciphertext_index++] = text[i] 
                            + value_to_increase - LETTER_COUNT;
                } 
                else
                {
                     ciphertext[ciphertext_index++] = text[i] 
                            + value_to_increase;
                }
            }    
        }

      // terminate string
      ciphertext[ciphertext_index] = '\0';

      free(text);
      
      return ciphertext;
    }

    return NULL;
}
