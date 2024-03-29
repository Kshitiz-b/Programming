import java.util.Scanner;
public class Armstrong
{
	static void find(int n)
	{
		int origNum, remainder,  result=0;
		origNum=n;
		while(origNum!=0)
		{
			remainder = origNum % 10;
			result += Math.pow(remainder, 3);
			origNum /= 10;	
		}
		if (result == n)
			System.out.printf("%d is an Armstrong number\n", n);
		else
			System.out.printf("%d is not an Armstrong number\n", n);
	}
	
	public static void main(String[] args)
	{
		int n;
		try (Scanner scan = new Scanner(System.in)) {
			System.out.printf("Enter an Integer: ");
			n = scan.nextInt();
		}
		find(n);
	}
}