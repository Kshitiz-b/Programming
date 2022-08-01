import java.util.Scanner;
public class J10 {
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            String s = sc.nextLine();
            System.out.println("You Entered String " + s);

            int n = sc.nextInt();
            System.out.println("You Entered Integer " + n);

            float f = sc.nextFloat();
            System.out.println("YOu Entered Float " + f);
        }

    }
}
