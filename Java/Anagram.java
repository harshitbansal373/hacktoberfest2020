package programs;
import java.util.Scanner;
import java.lang.String;

public class Anagram {

	public static void main(String args[])
	{
		String str1,str2;int count[] = new int[256];
		int co=0;
		Scanner in = new Scanner (System.in);
		System.out.println("enter two strings");
		str1 = in.nextLine();
		str2 = in.nextLine();
		if(str1.length() != str2.length())
			System.out.println("not an anagram");
		else
		{
			for(char c: str1.toCharArray())
			{
				int index = (int) c;
				count[index]++;
			}
			for(char c: str2.toCharArray())
			{
				int index = (int) c;
				count[index]--;
			}
		}
		for(int i=0;i<256;i++)
		{
			if(count[i]==0)
				co++;
		}
		if(co==256)
			System.out.println("Anagram");
		else
			System.out.println("Not an anagram");
	}
}
