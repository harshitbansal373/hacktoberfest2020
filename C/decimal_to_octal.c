#include <stdio.h>

int main()
{
    long long decimal, tempDecimal, octal;
    int i, rem, place = 1;

    octal = 0;

    printf("Enter any decimal number: ");
    scanf("%lld", &decimal);

    tempDecimal = decimal;

    while(tempDecimal > 0)
    {
        rem = tempDecimal % 8;

        octal = (rem * place) + octal;

        tempDecimal /= 8;

        place *= 10;
    }

    printf("\nDecimal number = %lld\n", decimal);
    printf("Octal number = %lld", octal);

    return 0;
}
