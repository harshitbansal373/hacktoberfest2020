#include<stdio.h>
#include<string.h>
struct stud{
	int roll;
	char n[100];
	char dept[100];
	int year;
}s1;
int main()
{
	printf("Enter student university roll no : ");
	scanf("%d",&s1.roll);
	fflush(stdin);
	printf("Enter student name : ");
	gets(s1.n);
	printf("Enter department of student : ");
	gets(s1.dept);
	printf("Enter current year of student : ");
	scanf("%d",&s1.year);
	printf("Student university roll no : ");
	printf("%d",s1.roll);
	printf("\nStudent name : ");
	puts(s1.n);
	printf("\nStudent department : ");
	puts(s1.dept);
	printf("\nStudent current year : %d",s1.year);
	return 0;
}
	
