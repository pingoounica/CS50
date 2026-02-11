#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

// function
void cipherCode(char *, int);

// Make sure program was run with just one command-line argument
int main(int argc, char *argv[])
{
    // validates key by the user
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        //checks if it's a digit
        if (isalpha(argv[1][i]) != 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //converts key string to integer
    int key = atoi(argv[1]);

    // asks user for a text
    char *plaintext = get_string("plaintext:  ");

    //starts function that ciphers the text
    cipherCode(plaintext, key);
}

void cipherCode(char *t, int k)
{
    printf("Ciphertext: ");

    //runs through each letter of the text
    for (int i = 0; t[i] != '\0'; i++)
    {
        //checks if it's string
        if (isalpha(t[i]) != 0)
        {
            //checks if it's uppercase
            if (isupper(t[i]) != 0)
            {
                //applies ASCII's formula uppercase letters
                printf("%c", ((t[i] - 'A' + k) % 26) + 'A');
            }
            //applies ASCII's formula lowercase letters
            else
            {
                printf("%c", ((t[i] - 'a' + k) % 26) + 'a');
            }
        }
        //keeps non strings
        else
        {
            printf("%c", t[i]);
        }
    }
    printf("\n");
}