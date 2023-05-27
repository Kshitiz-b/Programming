
// Simple Sieve algorithm to find all the Prime Numbers till n
import java.util.*;

public class Sieve {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int n = sc.nextInt();
        Boolean[] isPrime = new Boolean[n + 1];
        Arrays.fill(isPrime, Boolean.TRUE);

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j <= n; j = j + i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                System.out.print(i + " ");
        }

        sc.close();
    }

}
