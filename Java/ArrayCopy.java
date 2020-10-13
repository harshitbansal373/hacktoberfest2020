import java.util.Scanner;
class ArrayCopy
{
	public static void main (String args[])
	{
		Scanner scInt = new Scanner(System.in);
		int N;
		int[] arr1;
		int[] arr2;

		System.out.print("Masukkan jumlah elemen array: ");
		N = scInt.nextInt();
		arr1 = new int[N];
		arr2 = new int[N];

		for(int i=0; i<N; i++)
		{
			System.out.print("Isi array1, elemen ke-" + i +" : ");
			arr1[i] = scInt.nextInt();
			arr2[i] = arr1[i];
		}
		for(int i=0; i<N; i++)
		{
			System.out.println("array2 indeks ke-" +i+ " : " + arr2[i]);
		}
	}
}
