import java.util.Scanner;
public class P1
{
    public static void main(String[] args)
    {
        int x, count=0;
        try (Scanner input = new Scanner(System.in)) {
            x = input.nextInt();
        }
        for(int i=1;i<=x;i++)
        {
            if(x%i==0)
            {
                count += 1;
            }
            
        }
        if (count == 2)
        {
            System.out.println("prime");
        }
        else
        {
            System.out.println("not prime");
        }
    }
}