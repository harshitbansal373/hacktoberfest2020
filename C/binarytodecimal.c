#include<stdio.h>
#include<string.h>
#include<math.h>
int convert(int bin);// function declaration
void main()
{
    int bin;
    printf("Enter binary number: ");
    scanf("%d",&bin);
    int decimal= convert(bin);// function calling
    printf("The decimal number is: %d",decimal);
}
int convert(int bin)
{
    int dec=0,i=0,digit;
    do{
        digit=bin%10;
        dec=dec+digit*pow(2,i);
        i++;
        bin=bin/10;
    }while(bin!=0);
    return dec;
}