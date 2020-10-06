import java.util.Scanner;

public class palindrome {

    public static void main(String[] args) {

        Scanner reader = new Scanner(System.in);
        int flag=1;
        System.out.print("Enter a string: ");  
        String str=reader.nextLine();
        for (int i=0;i<str.length()/2 ; i++) {
            if(str.charAt(i)!=str.charAt(str.length()-i-1)){
                flag=0;
                break;
            }
        }
        if(flag==0){
            System.out.println(str+" is NOT a pallindrome.");
        }
        else{
            System.out.println(str+" is a pallindrome.");
        }
    }
}

