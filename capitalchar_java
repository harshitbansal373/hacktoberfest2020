/**

Write a Java program which accept string from user and count number of capital characters. 

Input :   “Marvel Super Heros” 

Output :   3
 
**/

import java.util.*;

class stringDemo
{  
  public int CountCapital(String input)  
  {  
    char Arr[]=input.toCharArray();
    int len=Arr.length;
    int icnt=0;

    for(int i=0;i<len;i++)
    {
       if((Arr[i]>='A')&&(Arr[i]<='Z'))
       {
          icnt++;
       }
    }
    
    return icnt;
  }
} 

class DEMO561
{
  public static void main(String arg[])
  {

    Scanner sobj=new Scanner(System.in);

    System.out.println("enter string");

    String str=sobj.nextLine();
    stringDemo nobj=new stringDemo();

    int iRet=0;

    iRet = nobj.CountCapital(str);

    System.out.println("string count is" + iRet);


}


}
