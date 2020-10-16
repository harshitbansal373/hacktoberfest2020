#include<stdio.h>
#include<string.h>
struct stud{
	long roll;
	char name[50];
	int year;
	char dept[50];
}s;
int main()
{
	printf("Enter student name : ");
	gets(s.name);
	return 0;
}
