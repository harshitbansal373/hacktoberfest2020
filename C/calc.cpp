// #6 perform basic arithmetic operation
#include <stdio.h>
int main()
{	char o;
     scanf("%c", &o);
	printf("Enter two operands: ");
	int x,y;
     printf("Enter an operator (+, -, *,/): ");

    scanf("%d %d",&x, &y);

    switch(o)
    {
        case '+':
            printf("%d + %d = %d",x, y, x + y);
            break;

        case '-':
            printf("%d - %d = %d",x, y, x - y);
            break;

        case '*':
            printf("%d * %d = %d",x, y, x * y);
            break;

        case '/':if(x>y)
        {
            printf("%d / %d = %d",x, y, x / y);
    }
    else
    {printf("%d / %d = %d",x, y, y / x);}
            break;
        default:
            printf("wrong operator!!!");
    }

    return 0;
}
