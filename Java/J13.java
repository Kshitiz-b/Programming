class Parent {
    void fun() {
        System.out.println("PARENT");
    }
}

class Child extends Parent {
    @Override
    void fun() {
        super.fun();
        System.out.println("CHILD");
    }
}

public class J13 {
    public static void main(String[] arsgs) {
        Parent p = new Child();
        p.fun();
    }
}
