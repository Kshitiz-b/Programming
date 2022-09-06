import java.util.Scanner;

class Number {
    private double number;

    public Number(double aNumber) {
        super();
        number = aNumber;
    }

    public boolean isOdd() {
        return number % 2 == 1;
    }

    public boolean isEven() {
        return number % 2 == 0;
    }

    public boolean isPositive() {
        return number > 0;
    }

    public boolean isNegative() {
        return number < 0;
    }

    public boolean isZero() {
        return number == 0;
    }

    public boolean isPrime() {
        for (int i = 2; i < number; i++)
            if (number % i == 0)
                return false;
        return true;
    }

    public double getFact() {
        double fact = 1;
        for (int i = 1; i <= number; i++)
            fact = fact * i;
        return fact;
    }

    public double getSqrt() {
        return Math.sqrt(number);
    }

    public double getSqr() {
        return number * number;
    }

    public double sumDigits() {
        double sum = 0;
        int temp = (int) number;
        while (temp > 0) {
            sum += (temp % 10);
            temp /= 10;
        }
        return sum;
    }

    public double getReverse() {
        double rev = 0;
        int temp = (int) number;
        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp /= 10;
        }
        return rev;
    }

    public void dispBinary() {
        System.out.println(Integer.toBinaryString((int) number));
    }
}

public class NumberDemo {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter a Number: ");
            int input = sc.nextInt();
            Number nm = new Number(input);

            System.out.println("isOdd " + nm.isOdd());
            System.out.println("isEven " + nm.isEven());
            System.out.println("isZero " + nm.isZero());
            System.out.println("isPrime " + nm.isPrime());
            System.out.println("Factorial: " + nm.getFact());
            System.out.println("Sqrt: " + nm.getSqrt());
            System.out.println("Sqr: " + nm.getSqr());
            System.out.println("Reverse: " + nm.getReverse());
            System.out.println("Sum: " + nm.sumDigits());
        }
    }
}