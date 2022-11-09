import java.util.Scanner;

public class shape {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double radius = sc.nextDouble();
        double side = sc.nextDouble();
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        sc.close();
        Circle c = new Circle(radius);
        c.Area();
        Square s = new Square(side);
        s.Area();
        Rectangle r = new Rectangle(length, breadth);
        r.Area();
    }
}

class Shape {
    double length;
    double breadth;
    double radius;
    double area;

    Shape() {
        length = 0;
        breadth = 0;
    }

    Shape(double l, double b) {
        length = l;
        breadth = b;
    }

    void Area() {
        area = length * breadth;
        System.out.println("The Area is: " + area);
    }
}

class Circle extends Shape {
    Circle(double radius) {
        super(radius, radius);
    }

    void Area() {
        area = length * breadth;
        System.out.println("The Area is " + area);
    }
}

class Square extends Shape {
    Square(double length) {
        super(length, length);
    }
}

class Rectangle extends Shape {
    Rectangle(double length, double breadth) {
        super(length, breadth);
    }
}