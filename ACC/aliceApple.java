import java.util.*;

public class aliceApple {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int apple = sc.nextInt();
        int cnt=0, sum=0;
        while(sum<apple) {
            cnt++;
            sum += (12*cnt*cnt);
        }
        System.out.println(8*cnt);

        sc.close();
    }
}
