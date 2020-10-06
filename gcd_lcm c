#include<stdio.h>

int main()
{
    int no1=0,no2=0,i=0,j=0,l_a=0,l_b=0;
    int arr[50],brr[50];


    printf("Enter the two numbers:\n\n");
    scanf("%d %d",&no1,&no2);

    for(i=1;i<=(no1/2);i++)
    {
        if((no1%i)==0)
        {
            arr[j]=i;
            printf("%d\t",arr[j]);

            j++;
        }
    }
    arr[j]=no1;

    j=0;

    printf("\n\n");

    for(i=1;i<=(no2/2);i++)
    {
        if((no2%i)==0)
        {
            brr[j]=i;
            printf("%d\t",brr[j]);

            j++;
        }
    }
    brr[j]=no2;





    l_a=strlen(arr);
    l_b=strlen(brr);

    for(i=l_a-1;i>=0;i--)
    {
        for(j=l_b;j>=0;j--)
        {

            printf("%d\t",arr[i]);

           /** if(arr[i]==brr[j])
            {
                printf("GCD is %d %d",arr[i],brr[j]);
            } **/
        }
    }


    for(i=0;i<l_a-1;i++)
    {
        for(j=0;j<=l_b;j++)
        {
          /**  if(arr[i]==brr[j])
            {
                printf("LCM is %d %d",arr[i],brr[j]);
            } **/
        }
    }

    return 0;
}
