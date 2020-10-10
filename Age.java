import java.util.*;
public class YearsAge
{
    public static void main(String[] args) {
       Scanner sc= new Scanner (System.in);
        int Age = sc.nextInt();
    
    if (Age==0)
    System.out.println("Are you a GHOST learning in Sololearn 🥵.");
    
 else if (Age<=5)
    System.out.println("I love babies , but child please give your phone to some elder you're not supposed to be here in Sololearn.");
    
    else if(Age==8)
   {
    System.out.println("Do you know that Mark Zukerburg was a coder at 8 and so do you🥳 keep it up!!!");
    }
   
    else if (Age>=6 && Age<=12 && Age!=8)
   {
    System.out.println("Hi JUNIOR!!!🧐 Happy coding!!! ");
    }
  
    else if (Age>=13 && Age<=18 && Age!=14)
   {
    System.out.println("Hello teen!!! So this means that you have chosen Programming as your life-goal🧐🥳");
    }
   
    else if (Age==14)
    {
    System.out.println(" So you are of my age!!! Great!!! I am also 14!!!. Friend? ");
    } 
  
    else if (Age>18 && Age<28)
   {
    System.out.println("Looking for a carrier in coding??? ");
    }
   
    else if (Age>=28 && Age<45)
  {
    System.out.println("Hi uncle/aunt. Are you married? If not then you are going to live a very happy life ");
    }
   
    else if(Age>=45 && Age<60)
   {
    System.out.println("FUN FACT!!! At this age you are using a hair color 🤭🤫 !!!");
    }
   
    else if (Age>=60 && Age<100)
   {
    System.out.println("Hi Grandma/Grandpa!!! . Why are you here? Please take rest .");
    }
   
    else if (Age==100)
   { System.out.println("So happy for you !!!! You have lived till 100 years. Congrats 🥳");
    }
    
    else if (Age>100 && Age<=150)
   {
    System.out.println("No words sorry . Are you sure that you are" + Age);
    System.out.print(" years old ");
    }
   
    else if (Age>150 && Age<10000)
  {
    System.out.println("Alert . A ghost !!!! . Have you come out of a grave ???????" );
   } 
  
    else if (Age>=10000)
   {
    System.out.println("Your device is going to blast!!! Go to a safe place !!");
    }
   
    else
   {
   System.out.println("Sorry I could not complete the request.");//Made by Poorvika
  }      }
}
