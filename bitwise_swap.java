public class bitwise_swap{  

	public static void main(String[] args){
		int x = 10;
		int y= 15;
		System.out.println("Before swapping:-");
		System.out.println("\tx= " + x + ", y= " + y);
		x = x ^ y;
		y = x ^ y;
		x = x ^ y;
		System.out.println("\nAfter swapping:-");
		System.out.println("\tx= " + x + ", y= " + y);
	}
}
