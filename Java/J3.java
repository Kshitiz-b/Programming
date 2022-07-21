// Non Primitive Data Type
class Point {
    int x;
    int y;
}

class J3 {
    public static void main(String[] args) {
        Point p1 = new Point();
        p1.x = 10;
        p1.y = 20;

        Point p2 = p1;
        p2.x = 30;

        System.out.println(p1.x);
        System.out.println(p2.x);
        
    }
}