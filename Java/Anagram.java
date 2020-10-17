import java.util.Scanner;

public class Anagram {
    public static void  main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the First String: ");
        String string1 = sc.next();
        System.out.println("Enter the Second String: ");
        String string2 = sc.next();
        // string1 = string1.toLowerCase();        TO IGNORE CASE SENSITIVENESS IN STRINGS
        // string2 = string2.toLowerCase();

        boolean isAnagram = false;
        boolean visited[] = new boolean[string2.length()];

        if(string1.length() == string2.length()){

            for(int i=0; i<string1.length(); i++){
                char c = string1.charAt(i);
                isAnagram= false;

                for(int j=0; j< string2.length();j++){

                    if(string2.charAt(j)==c && !visited[j]){

                        visited[j]= true;
                        isAnagram= true;
                        break;
                    }
                }
                if(!isAnagram){
                    break;
                }
            }
        }
        if(isAnagram){
            System.out.println("Strings are ANAGRAMS! :)");
        }else{
            System.out.println("MISMATCHED! Not ANAGRAMS! :(");
        }    

    }
}