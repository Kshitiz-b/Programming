// Example of Abstract Class
abstract class Shape {
    int colour;
    int getColour() {
        return colour;
    }
    Shape(int c) {
        colour = c;
    }
    abstract double getArea();
}
class Square extends Shape {
    double side;
    Square(int c, double s) {
        super(c);
        side = s;
    }
    double getArea() {
        return side*side;
    }
}
public class J14 {
    public static void main(String[] args) {
        Square s = new Square(5, 10.0);
        System.out.println("The Area of the Square of side " + s.side + " and Colour Code " + s.colour + " is " + s.getArea());
    }
}
