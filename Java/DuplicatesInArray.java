package geeksforgeeks;
import java.util.*;

public class DuplicatesInArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int[]arr = new int[N];
		
		for(int i=0;i<N;i++) {
			
			arr[i] = scanner.nextInt();
			
		}
		
		
		duplicates(arr, N);
		
		
		
		
		

	}
	public static ArrayList<Integer> duplicates(int arr[], int n) {
		 // code here
		 int N = n;
		ArrayList<Integer> list1 = new ArrayList<Integer>();
		for(int i=0;i<N;i++) {
			for(int j=i+1;j<N;j++) {
				if(arr[i] == arr[j])
				{
					list1.add(i,arr[i]); 
				}
				
			}
		}
		
		
		if(list1.isEmpty()) {
			list1.add(0, -1);
			
		}
		System.out.println(list1);
		return list1;
		
       
    }

}
