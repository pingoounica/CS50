#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool valid_triangle( float a, float b, float c);

int main(void)
{
    float a=get_float("enter first lenght:");
    float b=get_float("enter second lenght:");
    float c=get_float("enter third lenght:");

bool valid_triangle (float a, float b,float c)

    {
        if (a <= 0 || b<=0 || c<=0)
        {
            return false;
        }
        if ((a+b<=c)|| (a+c<=b)||(b+c<=a))
        {
            return false;
        }
        return true;
    }

}