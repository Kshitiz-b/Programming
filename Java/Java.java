import java.util.Scanner;
public class Java
{
    public static void main(String[] args)
    {
        try (Scanner sc = new Scanner(System.in)) {
            String str1 = sc.nextLine();
            String str2 = sc.next();
            String newStr = "";
            
            
            for (int i=0;i<str1.length();i++)
            {
                newStr += str1.charAt(i);
                if(str1.charAt(i) == ' ')
                {
                    newStr = newStr + str2+ " ";
                }
            }
            
            System.out.println(newStr);
        }
    }
}
