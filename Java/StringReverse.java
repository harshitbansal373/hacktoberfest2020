import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String a = sc.next();
        String b = new StringBuilder(a).reverse().toString();
        // new StringBuilder(hi).reverse().toString()
        if(a.equals(b)) 
        {  
            System.out.println("Yes");
        } 
        else
        {
            System.out.println("No"); 

        }
        
    }
}



