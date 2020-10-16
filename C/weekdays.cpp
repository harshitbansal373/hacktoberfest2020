// #10 week days
#include <stdio.h>
int main() 
{	
    int x;
    printf("Enter an no from 1 to 7 : ");
    scanf("%d", &x);
    switch(x)
    {
        case 1:
            printf("sunday");
            break;

        case 2:
            printf("monday");
            break;

        case 3:
            printf("tuesday");
            break;

        case 4:
        
            printf("wednesday");
			break;
    	case 5: 
			printf("thursday");
			break;
    	case 6:
			printf("friday");
			break;
    	case 7:
			printf("saturday");
			break;
        default:
            printf("wrong day!!!");
    }
    
    return 0;
}
