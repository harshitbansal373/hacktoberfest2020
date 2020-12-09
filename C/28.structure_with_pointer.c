#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll_no;
    char name[20];

} *obj;

int main()
{
    //using malloc function
    obj = (struct student*)malloc(sizeof(struct student)*3);

    //using for loop to take input from user
    for(int i = 0; i < 3; i++)
    {
        printf("enter student roll no and name: ");
        scanf("%d%s", &obj[i].roll_no, obj[i].name);
    }


    printf("Values are: \n");
    //using for loop to display data on screen
    for(int j = 0; j < 3; j++)
    {
        printf("rollno: %d and name: %s\n",obj[j].roll_no, obj[j].name);
    }

    return 0;
}


/*

Output:

enter student roll no and name: 1 aman
enter student roll no and name: 2 srijika
enter student roll no and name: 3 anay
Values are: 
rollno: 1 and name: aman
rollno: 2 and name: srijika
rollno: 3 and name: anay

*/
