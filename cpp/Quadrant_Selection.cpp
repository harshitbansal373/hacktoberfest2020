#include <stdio.h> 
int main() { 
	long double x,y;
	scanf("%Lf\n%Lf",&x,&y);
	if(x==0 && y == 0){
    	printf("Origin");
    }
	else if(x==0){
    	printf("Y Axis");
    }
	else if(y==0){
    	printf("X Axis");
    }
	else if(x>0 && y > 0){printf("1");}
	else if(x>0 && y < 0){printf("4");}
	else if(x<0 && y > 0){printf("2");}
	else if(x<0 && y < 0){printf("3");}
    return 0;
}
