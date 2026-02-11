#include <cs50.h>
#include <stdio.h>

int main(void)
{
//asks for a name
    string name= get_string("What's your name?\n ");
    printf("Hello, %s\n", name);
}