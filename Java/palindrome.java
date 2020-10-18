import java.util.Scanner; //import the java scanner utility in order to read user input

public class palindrome { //define the new class

    public static void main(String[] args) { //begin the main method

        Scanner reader = new Scanner(System.in); //instantiate the scanner as 'reader'
        int flag=1; //declare a flag for us to check later to determine palindrome property
        System.out.print("Enter a string: ");  //prompt the user for a string in stdin
        String str=reader.nextLine(); //take the user's input and set it as 'str'
        for (int i=0;i<str.length()/2 ; i++) { //for each character in the first half of the string...
            if(str.charAt(i)!=str.charAt(str.length()-i-1)){ //...check the corresponding character in the opposite (mirrored) position...
                flag=0; //... and if the characters are not the same, disable our flag
                break; // don't bother evaluating the rest if we've decided it's not a palindrome
            }
        }
        if(flag==0){ //if our flag is disabled...
            System.out.println(str+" is NOT a pallindrome."); //...inform the user that the string is not a palindrome
        }
        else{ // otherwise (if the flag is NOT disabled)...
            System.out.println(str+" is a pallindrome."); //...tell the user we've found a palindrome!
        }
    }
}

