#include<stdio.h>
double LEAP(int);
int main(){

	int day;
	int year;
	int month;


	printf("Enter the month, day, year : ");
	scanf("%d%d%d",&month,&day,&year);
        double l = LEAP(year);



	switch(month-1){

		case 11:
			day = day+31;
		
		case 10:
			day=day+30;

		case 9: 
			day=day+31;

		case 8:
			day=day+30;

		case 7:
			day=day+31;

		case 6:
			day=day+31;

		case 5:
			day = day + 30;

		case 4:
			day = day + 31;

		case 3:
			day= day + 30;

		case 2:
			day = day + 31;

		case 1:
			if(LEAP()==1.0){
				printf("The year is a leap year.");
				day = day + 29 ;

			}else {
				printf("The year is not a leap year.");
				day = day + 28;

			}

		case 0:
			printf("Total days till date are : %d",day);
			break;

		default:
			printf("Invalid input");
	}

   return (0);
}
double LEAP(int year){


                if(((year%4)==0)||(((year%100)==0)&&(year%400)==0)){

                        return (1.0);

                }else {

                       return (0.0);

                }

}
