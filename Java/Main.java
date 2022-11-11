// import java.util.Scanner;
// class Shape {
//     int length;
//     int breadth;
//     double area;
//     Shape() {
//         length = 0;
//         breadth = 0;
//     }
//     Shape(int l, int b) {
//         length = l;
//         breadth = b;
//     }
// }
// class Circle extends Shape {
//     int r;
//     void Area(int r) {
//         area = 3.14*r*r;
//         System.out.println(area);
//     }
// }
// class Square extends Shape {
//     int s;
//     void Area(int s) {
//         area = s*s;
//         System.out.println(area);
//     }
// }
// class Rectangle extends Shape {
//     int l, b;
//     void Area(int l, int b) {
//         area = l*b;
//         System.out.println(area);
//     }
// }
// public class Main {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int r = sc.nextInt();
//         int s = sc.nextInt();
//         int l = sc.nextInt();
//         int b = sc.nextInt();
//         sc.close();
        
//         Circle sh1 = new Circle();
//         Square sh2 = new Square();
//         Rectangle sh3 = new Rectangle();
//         sh1.Area(r);
//         sh2.Area(s);
//         sh3.Area(l, b);
//     }
// }