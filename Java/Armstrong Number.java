import java.util.*;
import java.lang.*;
import java.io.*;

/*Math.pow() is import using java.lang package*/
class Main
{ 
  
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the number :");
		double n = sc.nextInt();
    double d=0;
    double m=n;
    double sum=0;
    while(n!=0)
   {
     d=n%10;
     sum=sum+ Math.pow(d, 3);
     n=n/10;
   }
    if(d==m)
    {System.out.println("Armstrong Number");}
    else
    {System.out.println("Not an Armstrong Number");}
	}
}
