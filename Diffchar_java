/**
 Write a java program which accept string from user and return difference between frequency of small characters and frequency of capital characters.

Input :   “MarvellouS” 

Output :   6 (8-2) 

 
**/

import java.util.*;

class stringDemo
{  
  public int Countdiff(String input)  
  {  
    char Arr[]=input.toCharArray();
    int len=Arr.length;
    int icnt=0;

    for(int i=0;i<len;i++)
    {
       if((Arr[i]>='a')&&(Arr[i]<='z'))
       {
          icnt++;
       }
       else if((Arr[i]>='A')&&(Arr[i]<='Z'))
       {
          icnt--;
       }


    }
    
    return icnt;
  }
} 

class DEMO563
{
  public static void main(String arg[])
  {

    Scanner sobj=new Scanner(System.in);

    System.out.println("enter string");

    String str=sobj.nextLine();
    stringDemo nobj=new stringDemo();

    int iRet=0;

    iRet = nobj.Countdiff(str);

    System.out.println("string count is" + iRet);


}


}

