interface GeometricObject {
    abstract public double getPerimeter();

    abstract public double getArea();

}

class Circle implements GeometricObject {
    private double radius;

    public Circle() {
        radius = 1.0;
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        double area = 3.14 * radius * radius;
        return area;
    }

    public double getPerimeter() {
        return 2 * 3.14 * radius;
    }

    public String toString() {
        return "Circle radius : " + radius + " \nArea : " + getArea() + " \nPerimeter : " + getPerimeter() + "\n";
    }

}

interface Resizable {

    abstract void resize(int P);
}

class ResizableCircle extends Circle implements Resizable {
    public double radius;

    public ResizableCircle() {
        radius = 1.0;
    }

    public ResizableCircle(double radius) {
        this.radius = radius;
    }

    public void resize(int P) {
        radius = (radius * P) / 100;
    }

    public double getArea() {
        double area = 3.14 * radius * radius;
        return area;
    }

    public double getPerimeter() {
        return 2 * 3.14 * radius;
    }

    public String toString() {
        return "Circle radius : " + radius + " \nArea : " + getArea() + " \nPerimeter : " + getPerimeter() + "\n";
    }

}

public class Test {
    public static void main(String[] args) {

        GeometricObject obj1 = new Circle(4);

        GeometricObject obj2 = new Circle();

        ResizableCircle obj3 = new ResizableCircle(4);

        System.out.println(obj1.toString());
        System.out.println(obj2.toString());
        obj3.resize(10);
        System.out.println(obj3.toString());

    }
}