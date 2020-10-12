import java.util.Scanner;
public class CornerElementsPrinting {

	public static void main(String[] args) {
		int i,j,m,n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the no. of rows and columns:");
		m=sc.nextInt();
		n=sc.nextInt();
		int arr[][]=new int[m][n];
		System.out.println("Enter the elements");
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			arr[i][j]=sc.nextInt();
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if((i==0||i==m-1)&&(j==0||j==n-1))
					System.out.print(arr[i][j]+"\t");
			}
			System.out.println();
			
			}

	}

}
