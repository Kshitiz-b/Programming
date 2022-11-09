// Method Overloading
class Base {
    void fun() {
        System.out.println("BASE");
    }
}

class Derived extends Base {
    @Override
    void fun() {
        System.out.println("DERIVED");
    }
}

public class J12 {
    public static void main(String[] args) {
        Base b = new Derived(); // if the methods in base and deriverd classes are static then the overloading will not work!
        b.fun();
    }
}
