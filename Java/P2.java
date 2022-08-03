import java.util.Scanner;
public class P2
{
    public static void main(String[] args)
    {
        double perimeter, area;
        try (Scanner input = new Scanner(System.in)) {
            double radius = input.nextDouble();
            
            if (radius>0)
            {
                perimeter = 2.0*radius*Math.PI;
                area = Math.PI*radius*radius;
            
                System.out.println(perimeter);
                System.out.println(area);
            }
            else
                System.out.println("Kindly enter non-zero positive integer");
        }
    }
}