#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int main(void)
{


    //Your program must prompt the user for a string of text using get_string.
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int senteces = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        //counts letters
        if (isalpha(text[i]))
        {
            letters++;
        }//counts words
        else if (text[i] == ' ')
        {
            words++;
        }//counts senteces
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            senteces++;
        }
    }
    //Coleman-Liau index
    float L = (float)letters / (float)words * 100;
    float S = (float)senteces / (float)words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}







