import java.util.*;

public class ArrayDuplicate {
    public static void main(String[] args) {
        int n, i, count = 0;
        try (Scanner sc = new Scanner(System.in)) {
            n = sc.nextInt();
            int A[] = new int[n];

            for (i = 0; i < n; i++) {
                A[i] = sc.nextInt();
            }

            int fr[] = new int[n];
            int visited = -1;

            for (i = 0; i < n; i++) {
                count = 1;
                for (int j = i + 1; j < n; j++) {
                    if (A[i] == A[j]) {
                        count++;

                        fr[j] = visited;
                    }
                }
                if (fr[i] != visited) {
                    fr[i] = count;
                }
            }
            for (i = 0; i < n; i++) {
                if (fr[i] > 1) {
                    System.out.println(A[i] + ": " + fr[i]);
                }

            }
        }
    }
}