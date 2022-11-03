// Example of Interfaces
interface Printable {
    void print();
}
class myClass implements Printable {
    public void print() {
        System.out.println("myClass");
    }
}
public class J15 {
    public static void main(String[] args) {
        myClass m = new myClass();
        m.print();
    }
}
