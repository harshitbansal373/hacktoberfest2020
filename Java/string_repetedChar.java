import java.util.Scanner;

public class string_repetedChar {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str;
        int i, j, count = 0, lastcount = 0;
        System.out.print("Enter the string :\n>>> ");
        str = scan.nextLine();
        char character = str.charAt(0);
        for (i = 0; i < str.length(); i++) {
            for (j = i + 1; j < str.length(); j++) {
                if (str.charAt(i) == str.charAt(j)) {
                    count++;
                }
            }
            if (count > 0) {
                if (lastcount < count) {
                    character = str.charAt(i);
                    lastcount = count;
                }
            }
            lastcount = count;
            count = 0;
        }
        System.out.println(character);
    }
}
