/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "vigenere_cipher.h"


int main(int argc, string argv[])
{
    // Validation of data entry.
    if (argc > 2)
    {
        printf("A lot of arguments!\n");
        return 1;
    }
    else if (argc == 1)
    {
        printf("Must be one argument\n");
        return 1;
    }
    else if (strlen(argv[1]) == 0)
    {
        printf("Argument cannot be an empty string\n");
        return 1;
    }
    else
    {
        string keyword = argv[1];
    
        for(int i = 0; keyword[i] != '\0'; i++)
        {
            if (!(isalpha(keyword[i])))
            {
                printf("Keyword must be exclusively from the alphabet!\n");
                return 1;
            }
        }  
       
        printf("plaintext: ");

        string str = GetString();
		
        if (str != NULL) 
        {
            printf("ciphertext: %s\n", encrypt(keyword, str));

            free(str);
        }
    
        return 0;
    }   
}    
