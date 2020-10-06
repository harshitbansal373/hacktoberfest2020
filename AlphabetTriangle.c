#include <stdio.h> 
#include <conio.h>
int main() 
{ 
    int i, j, n = 5; 
    for (i = 1; i <= n; i++) { 
        for (j = i; j <= n; j++) { 
            printf("%c", 'A' - 1 + j); 
        } 
        printf("\n"); 
    } 
    return 0; 
} 