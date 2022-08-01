// using buffer reader
import java.io.*;
public class J9 {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter the Integer: ");
        int x = Integer.parseInt(br.readLine());
        System.out.println("You Entered " + x);
    }
}
