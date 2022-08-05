import java.util.Scanner;
public class Palindrome
{
	static void find(String str, String revStr)
	{
		int strLen = str.length();
		for (int i = (strLen - 1);i>=0;i--)
		{
			revStr += str.charAt(i);
		}
		if (str.toLowerCase().equals(revStr.toLowerCase()))
		{
			System.out.printf("The given String is a Palindrome");
		}
		else 
			System.out.printf("The given String is not a Palindrome");
	}
	public static void main(String[] args)
	{
		String str, revStr="";
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter a String: ");
		str = scan.next();

		find(str, revStr);
	}
}