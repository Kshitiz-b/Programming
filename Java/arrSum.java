import java.util.*;

public class arrSum {
    public static void main(String[] args) {
        int n, i, j, X;

        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the size of Array: ");
            n = sc.nextInt();

            int A[] = new int[n];
            System.out.println("Enter he elements of the Array:");
            for (i = 0; i < n; i++) {
                A[i] = sc.nextInt();
            }

            System.out.println("Enter the required Sum: ");
            X = sc.nextInt();

            for (i = 0; i < (n - 1); i++) {
                for (j = 0; j < n; j++) {
                    if (A[i] + A[j] == X) {
                        System.out.println("The pairs are: " + A[i] + " " + A[j]);
                    }
                }
            }
        }
    }
}