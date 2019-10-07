// Dhananjay Yelwande

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int cents;
    do
    {
        // Accepts user input in decimals
        float dollars = get_float("Owed change: ");
        // Rounds cents to nearest penny
        cents = round(dollars * 100);
    }
    while (cents <= 0);

    // Conversion of user's inputted dollars
    int quarters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = ((cents % 25) % 10) % 5;

    printf("Quarters : %d\nDimes : %d\nNickels : %d\nPennies : %d\nTotal coins : %d\n",quarters,dimes,nickels,pennies, quarters + dimes + nickels + pennies);
}
