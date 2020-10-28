//Program to find Factorial of a number using RECURSION

#include <stdio.h>
int factorial(int num);

int main(){
	int number,ans;
	printf("Enter the number whose factorial is to be found: ");
	scanf("%d",&number);
	ans=factorial(number);
	printf("The factorial is: %d\n",ans);
}


//Finding the factorial using recursive funtion
int factorial(int num){
	if(num==0)
		return 1;
	else
		return num*factorial(num-1);
}