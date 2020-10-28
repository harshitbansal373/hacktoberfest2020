#include <stdio.h>
 
int main()
{
	char Operator;
	float num1, num2;
	
	printf("Please Enter Calculation: ");
  	scanf("%f %c %f",&num1, &Operator, &num2);
  	
  	if(Operator == '+')
  	{
  		printf("%.2f", num1 + num2);
  	}
  	else if(Operator == '-')
  	{
  		printf("%.2f", num1 - num2);
  	}
  	else if(Operator == '*')
  	{
  		printf(" %.2f", num1 * num2);
  	}
  	else if(Operator == '/')
  	{
  		printf(" %.2f",  num1 / num2);
  	}
  	else
  	{
  		printf("\n Enetered an Invalid Operator ");
	}
	
  	return 0;
}