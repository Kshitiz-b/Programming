import java.util.*;

public class Remainder {
    public static int crt(int n, int div[], int rem[]) {
        int i, x = 1;
        while (true) {
            for (i = 0; i < n; i++) {
                if (x % div[i] != rem[i])
                    break;
            }
            if (i == n)
                return x;
            x++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans;
        int[] div = new int[n];
        int[] rem = new int[n];

        for (int i = 0; i < n; i++) {
            div[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            rem[i] = sc.nextInt();
        }

        ans = crt(n, div, rem);
        System.out.println(ans);

        sc.close();
    }
}
