import java.util.Scanner;
public class Employee 
{
public static void main(String args[])
{
Scanner sc= new Scanner(System.in);
System.out.println("Enter Employee name");
String name = sc.nextLine();
System.out.println("Enter Employee salary");
float salary = sc.nextfloat();
System.out.println("Employee name:"+name);
System.out.println("Salary:"+salary);
}}
