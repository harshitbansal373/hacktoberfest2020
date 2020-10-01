import java.util.Scanner;

public class fibonacci {

    public static void main(String[] args) {

        Scanner reader = new Scanner(System.in);
        int a=0;
        int b=1;
        int c=1;

        System.out.print("Enter number of terms: ");  
        int num=reader.nextInt();
        System.out.print(a+", "+b+", "+c+", ");
        for (int i=0;i<num; i++) {
            a=b;
            b=c;
            c=a+b;
            System.out.print(c+", ");
        }
    }
}