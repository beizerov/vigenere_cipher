/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "Cipher.h"


int main(int argc, string argv[])
{
    // Check input data
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
        string key = argv[1];
    
        for(int i = 0, n = strlen(key); i < n; i++)
        {
            if (!(isalpha(key[i])))
            {
                printf("Key must be exclusively from the alphabet!\n");
                return 1;
            }
        }  
       
        string text = GetString();
       
        string result = Cipher(key, text);
		
        if (result != NULL) 
        {
            printf("%s\n", result);

            free(result);
        }
    
        return 0;
    }   
}    
