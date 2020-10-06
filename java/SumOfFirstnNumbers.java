import java.util.Scanner;

// Other imports go here
// Do NOT change the class name

public class SumOfFirstnNumbers
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      int sum=0;
      for(int i=1;i<=n;i++)
      {
        sum+=i;
      }
      System.out.println(sum);
    }
}