import  java.util.Scanner;

public class factorial
{
	static void find(int n)
	{
		int f=1;
		
		if (n==0)
		{
			f = 1;
			System.out.printf("The Factorial of %d = %d", n, f);
		}
		for(int i=1;i<=n;i++)
		{
			f = f*i;
		}
		System.out.printf("The Factorial of %d = %d", n, f);
	}

	public static void main(String[] args)
	{
		int n;
		try (Scanner scan = new Scanner(System.in)) {
			System.out.println("Enter a number: ");
			n = scan.nextInt();
		}
		find(n);
	}
}