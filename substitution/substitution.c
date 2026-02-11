#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//function
void substitution(char *, char*);

// Make sure program was run with just one command-line argument
int main(int argc, char *argv[])
{
    // validates key by the user
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must have 26 chars.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        //checks if char is alphabetic
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetic characters. \n");
            return 1;
        }
        //loops to check repetitions
        for (int r = i + 1; r < strlen(argv[1]); r++)
        {
            //compares upper to upper
            if (toupper(argv[1][r]) == toupper(argv[1][i]))
            {
                printf("Key must only contain one of each alphabetic character. \n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");

    //makes cipher function
    substitution(text, argv[1]);
}

//runs function
void substitution(char *t, char *k)
{
    printf("ciphertext: ");

    //loops thought text
    for (int i = 0; i < strlen(t); i++)
    {
        if (isalpha(t[i]) != 0)
        {
            //matching same index
            if (isupper(t[i]) != 0)
            {
                int index = t[i] - 'A';
                printf("%c", toupper(k[index]));
            }
            else
            {
                //matches key by ASCII's values
                int index = t[i] - 'a';
                printf("%c", tolower(k[index]));
            }
        }
        //Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
        else
        {
            printf("%c", t[i]);
        }
    }
    //After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
    printf("\n");
}