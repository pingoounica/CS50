#include <stdio.h>
#include<cs50.h>
#include <math.h>

int main(void)
{
    long x = get_long("Enter the credit/debit card number: ");
    int digit = 0, sum = 0;

    long y = x;

//checksum card digits

    while (y != 0)
    {
        int sumeven = 0, sumodd = 0;
        int rem = y % 10;
        digit++;
        //if digit is even
        if (digit % 2 == 0)
        {
            int multiply = rem * 2;
            if (multiply == 0)
            {
                sumeven += multiply;
            }

            else
            {
                while (multiply != 0)
                {
                    sumeven += multiply % 10;
                    multiply /= 10;
                }
            }
        }
        //if digit is odd
        else
        {
            sumodd += rem;
        }
        //- last digit from y
        y /= 10;

        sum += sumeven + sumodd;
    }


//checks for valid credit/debit card
    if (digit != 13 && digit != 15 && digit != 16)
    {
        printf("INVALID\n");
    }

    else if (sum % 10 == 0)
    {
        //checks if it's mastercard
        if (digit == 16)
        {
            if (x / 100000000000000 >= 51 && x / 100000000000000 <= 55)
            {
                printf("MASTERCARD\n");
            }
            //checks if it's VISA
            else if (x / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else    //if digit is not 16
            {
                printf("INVALID\n");
            }
        }
        //checks if it's AMEX
        else if (digit == 15)
        {
            if (x / 10000000000000 == 34 || x / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }


        //checks if it's VISA
        else  if (digit == 13)
        {
            if (x / 1000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    else
    {
        printf("INVALID\n");
    }
}