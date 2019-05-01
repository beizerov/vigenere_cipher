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

        int text_length = strlen(text);
        // The value_to_increase variable to store the value by which to 
        // increase the character value when encrypting.
        int value_to_increase = 0;

        // Changes characters of the original text into ciphertext
        for (int i = 0, j = 0; i < text_length; i++)
        {   
            if (isalpha(text[i]))
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

            if (isalpha(text[i]))
            {   
                if (isupper(text[i]) && (text[i] + value_to_increase) > 'Z')
                {
                     ciphertext[i] =  text[i] 
                            + value_to_increase - LETTER_COUNT;
                }
                else if (
                         islower(text[i]) && (text[i] + value_to_increase) > 'z'
                )
                {
                     ciphertext[i] = text[i] 
                            + value_to_increase - LETTER_COUNT;
                } 
                else
                {
                     ciphertext[i] = text[i] 
                            + value_to_increase;
                }
            }
            else
            {
                ciphertext[i] = text[i];
            }    
        }

      // terminate string
      ciphertext[text_length] = '\0';

      free(text);
      
      return ciphertext;
    }

    return NULL;
}
