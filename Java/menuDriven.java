import java.util.Scanner;

public class menuDriven {
	static void factorial() {
		int n, i;
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter a number: ");
		n = scan.nextInt();

		int f = 1;

		for (i = 1; i <= n; i++) {
			f = f * i;
		}
		System.out.printf("The Factorial of %d = %d", n, f);
	}

	static void armstrong() {
		int n;
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter an Integer: ");
		n = scan.nextInt();

		int origNum, remainder, result = 0;
		origNum = n;
		while (origNum != 0) {
			remainder = origNum % 10;
			result += Math.pow(remainder, 3);
			origNum /= 10;
		}
		if (result == n)
			System.out.printf("%d is an Armstrong number", n);
		else
			System.out.printf("%d is not an Armstrong number", n);
	}

	static void palindrome() {
		String str, revStr = "";
		Scanner scan = new Scanner(System.in);
		System.out.printf("Enter a String: ");
		str = scan.next();

		int strLen = str.length();
		for (int i = (strLen - 1); i >= 0; i--) {
			revStr += str.charAt(i);
		}
		if (str.toLowerCase().equals(revStr.toLowerCase())) {
			System.out.printf("The given String is a Palindrome");
		} else
			System.out.printf("The given String is not a Palindrome");
	}

	public static void main(String[] args) {
		int choice;
		char reply;
		Scanner scan = new Scanner(System.in);

		while (true) {
			System.out.printf("1. To find a Factorial of a given number.\n");
			System.out.printf("2. To check a given number is Armstrong or not.\n");
			System.out.printf("3. To check a given string is Palindrome or not.\n");
			System.out.printf("\nEnter Your Choice:\n");
			choice = scan.nextInt();
			switch (choice) {
				case 1:
					factorial();
					break;
				case 2:
					armstrong();
					break;
				case 3:
					palindrome();
					break;
				default:
					System.out.printf("\nWrong Input\n");
					break;
			}

			Scanner re = new Scanner(System.in);
			System.out.printf("\nDo You Want To Continue (Y/N): \n");
			reply = re.next().charAt(0);

			if ((reply == 'n') || (reply == 'N')) {
				break;
			}
		}
	}
}