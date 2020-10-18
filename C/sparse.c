#include<stdio.h>
#include<stdlib.h>
char compare(int x,int y)
{
 if(x<y)
  return('<');
 else if(x>y)
  return('>');
 else
  return('=');
}
void add(int M1[][3],int M2[][3],int M3[][3])
{
 int i=1,j=1,k=1,t1,t2;
 if(M1[0][0]!=M2[0][0]||M1[0][1]!=M2[0][1])
  return;
 M3[0][0]=M1[0][0];
 M3[0][1]=M1[0][1];
 t1=M1[0][2];
 t2=M2[0][2];
 while(i<=t1 && j<=t2)
 {
  switch(compare (M1[i][0],M2[j][0]))
  {
   case '=':
            switch(compare(M1[i][1],M2[j][1]))
            {
             case '=':
                      M3[k][0]=M1[i][0];
                      M3[k][1]=M1[i][1];
                      M3[k][2]=M1[i][2]+M2[j][2];
                      i++;
                      j++;
                      k++;
                      break;
             case '<':
                      M3[k][0]=M1[i][0];
                      M3[k][1]=M1[i][1];
                      M3[k][2]=M1[i][2];
                      i++;
                      k++;
                      break;
             case '>':
                      M3[k][0]=M2[j][0];
                      M3[k][1]=M2[j][1];
                      M3[k][2]=M2[j][2];
                      j++;
                      k++;
                      break;
            }
            break;
   case '<':
            M3[k][0]=M1[i][0];
            M3[k][1]=M1[i][1];
            M3[k][2]=M1[i][2];
            i++;
            k++;
            break;
   case '>':
            M3[k][0]=M2[j][0];
            M3[k][1]=M2[j][1];
            M3[k][2]=M2[j][2];
            j++;
            k++;
            break;                                                               
  }
  if(i>t1)
  {
   M3[k][0]=M2[j][0];
   M3[k][1]=M2[j][1];
   M3[k][2]=M2[j][2];
   j++;
   k++;
  }
  if(j>t2)
  {
   M3[k][0]=M1[i][0];
   M3[k][1]=M1[i][1];
   M3[k][2]=M1[i][2];
   i++;
   k++;
  }
 }
 M3[0][2]=k-2;
 printf("Sum of The two Matrices:\n");
 for(i=0;i<k-1;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d\t",M3[i][j]);
  }
  printf("\n");
 }
}

int main()
{
 int m,n,i,j,t,r,c,e;
 printf("Enter Dimensions of the Matrices: ");
 scanf("%d%d",&m,&n);
 printf("Enter No. of Non-Zero Terms of 1st Matrix: ");
 scanf("%d",&t);
 int A[t+1][3];
 A[0][0]=m;
 A[0][1]=n;
 A[0][2]=t;
 for(i=1;i<=t;i++)
 {
  printf("Enter Row No., Column No. and %d Non-Zero Element Respectively: ",i);
  scanf("%d%d%d",&r,&c,&e);
  A[i][0]=r;
  A[i][1]=c;
  A[i][2]=e;
 }
 printf("Sparse Matrix A:\n");
 for(i=0;i<=t;i++)
 {
  for(j=0;j<3;j++)
   printf("%d\t",A[i][j]);
  printf("\n");
 }    
 printf("Enter No. of Non-Zero Terms of 2nd Matrix: ");
 scanf("%d",&t);
 int B[t+1][3];
 B[0][0]=m;
 B[0][1]=n;
 B[0][2]=t;
 for(i=1;i<=t;i++)
 {
  printf("Enter Row No., Column No. and %d Non-Zero Element Respectively: ",i);
  scanf("%d%d%d",&r,&c,&e);
  B[i][0]=r;
  B[i][1]=c;
  B[i][2]=e;
 }
 printf("Sparse Matrix B:\n");
 for(i=0;i<=t;i++)
 {
  for(j=0;j<3;j++)
   printf("%d\t",B[i][j]);
  printf("\n");
 }
 m=A[0][2];
 n=B[0][2];    
 int C[m+n+1][3];
 for(i=0;i<=m+n;i++)
 {
  for(j=0;j<3;j++)
  C[i][j]=0;
 }
 add(A,B,C);
 return 0;
}
