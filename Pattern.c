 ### Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space. ###

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   
                            
### Code ###
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int i, int b);
int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for(int i=n-1;i>-n;i--){
        for(int j=n-1;j>-n;j--){
            printf("%d ", max(abs(i), abs(j))+1);
        }
        printf("\n");
    }
    return 0;
}
int max(int i, int j){
    if(i>j){
        return i;
    }
    else{
        return j;
    }
}
