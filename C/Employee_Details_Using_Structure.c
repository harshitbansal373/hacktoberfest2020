#include<stdio.h>
#include<conio.h>
struct address
{
char addr1[20];
char addr2[10];
char city[10];
long int pincode;
}s;
struct employee
{
int empid;
char empname[10];
int bs,hra,da,ta,pf;

struct address s;
}e;
void main()
{

int net_sal;
clrscr();
printf("\n\t\t\t     Employee Details   \n");
printf("\n\t\t\t(Structure with in structure)\n");
printf("\n\t\t  ----------------------------------------\t\n");
printf("\n Enter the Employee id:");
scanf("%d",&e.empid);
printf("\n Enter the  employee name :");
scanf("%s",&e.empname);
printf("\n Enter the address1:");
scanf("%s",&e.s.addr1);
printf("\n Enter the address2:");
scanf("%s",&e.s.addr2);
printf("\n Enter the city:");
scanf("%s",&e.s.city) ;
printf("\n Enter the pincode:");
scanf("%ld",&e.s.pincode);
printf("\n Enter the basic salary");
scanf("%d",&e.bs);
printf("\n Enter the hra");
scanf("%d",&e.hra);
printf("\n Enter the Ta");
scanf("%d",&e.ta);
printf("\n Enter the Da");
scanf("%d",&e.da);
printf("\n Enter the Pf");
scanf("%d",&e.pf);
net_sal=(e.bs+e.hra+e.ta+e.da) -e.pf;
printf("\n\n\t\t\t EMPLOYEE DETAILS\n");
printf("\n\t\t\t ------------------\n");
printf("\n \t Employee id :\t\t%d",e.empid);
printf("\n \t Name :\t\t%s",e.empname);
printf("\n \t Address:\t%s\n\t\t\t%s",e.s.addr1,e.s.addr2);
printf("\n \t city :%s",e.s.city);
printf("\n \t pincode :%ld",e.s.pincode);
printf("\n\n Basic Salary:%d",e.bs);
printf("\n\n HRA:%d",e.hra);
printf("\n\n Da:%d",e.da);
printf("\n\n TA:%d",e.ta);
printf("\n\n PF:%d",e.pf);
printf("\n\n Net Salary:%d",net_sal);
getch();
}
