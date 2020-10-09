#include<stdio.h>
#include<string.h>
#include<conio.h>
void sort(char str[]){
   
    int i = 0,j,temp=0;
     for(i=0;str[i]!='\0';i++)
     {
        for (j=i+1;str[j]!='\0';j++){
            if(str[i]>str[j]){
                temp=str[j];
                str[j]=str[i];
                 str[i]=temp;

            }
        }
         
     }
   
}
void main(){
    char str1[30] ,str2[30] ;
    int i=0,j=0;
    printf("Enter the string 1 \n");
    gets(str1);
   // scanf("%[^\n]s",str1);
     printf("Enter the string 2 \n");
    gets(str2);
    sort(str1);
    sort(str2);
    
    
    if(strcmp(str1,str2)==0)
    printf("Anagram number \n");
    else
    {
        printf("Not a Aangram number \n");
    }
    
 
}