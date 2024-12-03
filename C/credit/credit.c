#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number = get_long("Number: ");

    long amex_length_15 = pow(10, 13);
    long mc_length_16 = pow(10, 14);
    long visa_length_13 = pow(10, 12);
    long visa_length_16 = pow(10, 15);

    //Hans Peter Luhn algorithm that checks card validity
    int index = 0, sum = 0;
    for (long cut_num = number; cut_num > 0; cut_num /= 10, index++)
    {
        int digit = cut_num % 10; //getting every digit
        if (index % 2 != 0)
        {
            int multiply = digit * 2; //multiplying every other digit starting from the end
            if (multiply >= 10)
            {
                multiply = multiply % 10 + multiply / 10;
            }

            sum += multiply; //adding products digits
        }
        else
        {
            sum += digit; //adding the remaining digits
        }
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    //Checking validity and identifying card type based on its first numbers and length
    if
    (
        ((number >= 34 * amex_length_15) && (number < 35 * amex_length_15))
        ||
        ((number >= 37 * amex_length_15) && (number < 38 * amex_length_15))
    )
    {
        printf("AMEX\n");
    }
    else if ((number >= 51 * mc_length_16) && (number < 56 * mc_length_16))
    {
        printf("MASTERCARD\n");
    }
    else if
    (
        ((number >= 4 * visa_length_13) && (number < 5 * visa_length_13))
        ||
        ((number >= 4 * visa_length_16) && (number < 5 * visa_length_16))
    )
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}