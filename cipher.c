/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "cipher.h"


/*
 * This function encrypts incoming text
 */
string cipher(string keyword, string plaintext)
{
    static const int LETTER_COUNT = 26;
	
    if (plaintext != NULL)
    {  
        string ciphertext = malloc(strlen(plaintext) + 1);

        if (ciphertext == NULL) {
            return NULL;
        }

        int plaintext_length = strlen(plaintext);
        // The value_to_increase variable to store the value by which to 
        // increase the character value when encrypting.
        int value_to_increase = 0;

        // Changes characters of the plaintext into ciphertext
        for (int i = 0, j = 0; i < plaintext_length; i++)
        {   
            if (isalpha(plaintext[i]))
            {
                // Get value for value_to_increase
                for (int keyword_length = strlen(keyword);;)
                {   
                    if (j == keyword_length)
                    {
                        j = 0;  // Return to the first character of the keyword
                        continue;
                    }
                    else if (isupper(keyword[j]))
                    {
                        value_to_increase = (keyword[j] - 'A');
                    }
                    else if (islower(keyword[j]))
                    {
                        value_to_increase = (keyword[j] - 'a');
                    }
                    
                    j++;  // Next character of keyword.
                    break;
                }
            }

            if (isalpha(plaintext[i]))
            {   
                if (
                    isupper(plaintext[i]) && (plaintext[i] 
                        + value_to_increase) > 'Z'
                )
                {
                     ciphertext[i] =  plaintext[i] 
                            + value_to_increase - LETTER_COUNT;
                }
                else if (
                         islower(plaintext[i]) && (plaintext[i] 
                            + value_to_increase) > 'z'
                )
                {
                     ciphertext[i] = plaintext[i] 
                            + value_to_increase - LETTER_COUNT;
                } 
                else
                {
                     ciphertext[i] = plaintext[i] 
                            + value_to_increase;
                }
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }    
        }

      // terminate string
      ciphertext[plaintext_length] = '\0';

      free(plaintext);
      
      return ciphertext;
    }

    return NULL;
}
