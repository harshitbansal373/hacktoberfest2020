#include<stdio.h>
  void main(){
  int max;
  printf("\nEnter the size of array ");
  scanf("%d",&max);
  int a[max],ele,i,j,re=-1,fr=-1,k=0,ch;
          while(k==0)     {
  printf("\nMenu\n1.Enter from rear\n2.Delete from front\n3.Display\n4.Exit\n");
  scanf("%d",&ch);
  switch(ch){
  case 1:
           if (re==-1){
           re++;
           fr=0;
           printf("Enter the element ");
           scanf("%d",&a[re]);
           }
          else if((((fr%max)-(re%max))==1)||((fr==0)&&(re==max-1))){
          printf("\nOverflow. Queue is full\n");
          }
          else {
          re=(re+1);
          ele=re%max;
          printf("Enter the element ");
          scanf("%d",&a[ele]);
          }
          break;
  case 2:
          if(fr==-1){
          printf("\n'Underflow'. Queue is empty\n");
          }
          else if((fr%max)==(re%max)){
          fr=-1;
          re=-1;
          printf("Last element is deleted");
  }
          else  {
          fr=(fr+1);
          printf("Element deleted ");

  }
          break;
  case 3:
          if(fr==-1){
          printf("\n'Underflow'. Queue is empty");
    }
          else if (fr<re){
          for(i=fr;i<=re;i++){
          printf("\n%d",a[i%max]);
  } }
          else{//re<fr
          for(i=fr;i<=re;i++){
          printf("\n%d",a[i%max]);
  }
 }       break;
  case 4:
          k=1;
          break;
  default :
          printf("\nEnter correct option\n");
  }       }
  }
