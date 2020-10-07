#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
 int str_length,pattern_length,j,i,count=0;
 char str[30],pattern[30];
 clrscr();
 printf("\nEnter a string: ");
 scanf("%s",str);
 printf("\nEnter a pattern to match: ");
 scanf("%s",pattern);
 str_length=strlen(str);
 pattern_length=strlen(pattern);
 printf("\nPattern matched at position: \t");
 for(i=0;i<str_length-pattern_length;i++)
 {
  for(j=0;j<pattern_length;j++)
  {
   if(str[i+j]==pattern[j])
   {
    count++;
   }
  }
  if(count==pattern_length)
  {
   printf("%d",i);
  }
  count=0;
 }
 printf("\n");
 getch();
}