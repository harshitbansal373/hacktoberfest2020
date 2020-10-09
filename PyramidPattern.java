import java.util.Scanner;

public class PyramidPattern
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of lines:");
        int row = Integer.parseInt(sc.next());
        for (int i=0; i<row; i++)
        {
            for (int j=row-i; j>1; j--)
            {
                System.out.print(" ");
            }
            for (int j=0; j<=i; j++ )
            {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
