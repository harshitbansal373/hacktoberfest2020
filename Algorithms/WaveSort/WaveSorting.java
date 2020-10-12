import java.util.Scanner;

public class WaveSorting {

	static void swap(int arr[], int a ,int b)
	{
		int temp;
		temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
	
	static void waveSorting(int [] arr)
	{
		for (int i=0;i<arr.length ;i= i+2)
		{
			//if current element is smaller than prevoius
			if(i>0 && arr[i-1] > arr[i])
				swap(arr, i-1 ,i);
			
			//if current element is smaller than next
			if(i<arr.length-1 && arr[i] <arr[i+1])
				swap(arr,i,i+1);
		}
	}
	static void printArray(int []arr) 
	{
		for(int i=0;i<arr.length;i++) 
		{
			System.out.println(arr[i] + " ");
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scn =new Scanner(System.in);
		
		int n=scn.nextInt();
		int arr[] =new int[n];
		
		for(int i=0;i<n;i++) {
			arr[i] = scn.nextInt();
		}
		
		waveSorting(arr);
		printArray(arr);
		
	}

}
