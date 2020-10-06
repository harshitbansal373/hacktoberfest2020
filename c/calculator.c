#include<stdio.h>

#include<conio.h>

#include<math.h>

#include<stdlib.h>

int main()

{
   int choise,a,b,ans;  
 
   do
  
  { printf("\n1\tadd\n2\tsubtract\n3\tmultiply\n4\tdivide\n5\tmodulas\n6\tpower\n7\tsquare root\n8\texit\nenter your choise\t");
 
   scanf("%d",&choise);
   
     if(choise>=1&&choise<=6)
       
 {printf("enter two number");
      
  scanf("%d%d",&a,&b);}
     
   else if(choise==7)
    
    {printf("enter a number");
   
     scanf("%d",&a);}
    
    else if(choise==8)
       
 exit(0);
  
      else
    
    printf("invalid output");
  
  switch(choise)
   
 {
        case 1:
  
      printf("addition = %d",a+b);
    
    break;
       
 case 2:
  
      printf("subtraction = %d",a-b);
  
      break;
       
 case 3:

        printf("multiply = %d",a*b);
   
     break;
   
     case 4:

            if(b!=0)

        printf("divide = %f",(float)a/b);
      
      else
         
   printf("division not possible");
      
  break;
       
 case 5:
       
     if(b!=0)
     
   printf("modulas = %d",a%b);
    
        else
           
 printf("modulus not possible");
  
      break;
  
      case 6:
    
        ans=pow(a,b);
    
    printf("power = %f",pow(a,b));
 
       break;

        case 7:
 
           ans=sqrt(a);
    
    printf("square root = %d",ans);
    
    break;
     
   default:

        printf("invalid input");
 
   }
  
