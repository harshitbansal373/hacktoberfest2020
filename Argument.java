public class Example { 
  
    public static int multiply(int a, int b) 
    { 
        return a + b; 
    } 
  
    public static void main(String[] args) 
    { 
        int x = 2; 
        int y = 5; 
  
        // the variables x and y are arguments 
        int sum = multiply(x, y); 
  
        System.out.println("SUM IS: " + sum); 
    } 
} 
