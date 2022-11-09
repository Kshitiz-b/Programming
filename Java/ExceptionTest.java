import java.io.*;
import java.util.*;

public class ExceptionTest {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("D:/OneDrive/Documents/Programming/Java/file.txt")); // this file is available
            Scanner in1 = new Scanner(new File("D:/OneDrive/Documents/Programming/Java/file1.txt")); // This file is not available

            in.close();
            in1.close();
        } catch (FileNotFoundException ex) {
            System.out.println("FileNotFound caught....\n" + ex);

        } finally {
            // Optional
            System.out.println("\nThis statement will execute regardless");
        }
    }
}
