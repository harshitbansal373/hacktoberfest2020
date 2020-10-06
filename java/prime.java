import java.util.Scanner;
import java.lang.Math; 

public class prime {

    public static void main(String[] args) {

        Scanner reader = new Scanner(System.in);
        int flag=1;
        System.out.print("Enter a number: ");  
        int num=reader.nextInt();
        for (int i=2;i<Math.sqrt(num) ; i++) {
            if(num%i==0){
                flag=0;
                break;
            }
        }
        if(flag==0){
            System.out.println(num+" is NOT a prime number.");
        }
        else{
            System.out.println(num+" is a prime number.");
        }
    }
}