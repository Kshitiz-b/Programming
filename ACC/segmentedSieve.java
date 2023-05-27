import java.util.*;

public class segmentedSieve {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int h = sc.nextInt();
        Boolean[] isPrime = new Boolean[h + 1];
        Arrays.fill(isPrime, Boolean.TRUE);

        for (int i = 2; i * i <= h; i++) {
            int sm = (l / i) * i;
            if (sm < l) {
                sm += i;
            }
            for (int j = 2*i; j <= h; j = j + i) {
                isPrime[j] = false;
            }
        }
        for (int i = l; i <= h; i++) {
            if (isPrime[i] == true && i != 1)
                System.out.print(i + " ");
        }
        sc.close();
    }
}
