#include<stdio.h>

void main() {
  int r;
  float pi = 3.14, area, cf;
  
  printf("Enter the radius of circle: ");
  scanf("%d",&r);
  
  area = pi * r * r;
  printf("Area of Circle = %f", area);
  
  cf = 2 * pi * r;
  printf("Circumference of Circle = %f", cf);
  
 }
 
 
 ## Output:
 
 # Enter the radius of circle: 5
 # Area of Circle = 78.000
 # Circumference of Circle = 31.4
