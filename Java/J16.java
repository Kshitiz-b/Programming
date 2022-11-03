interface myInt {
    default void fun1() {
        System.out.println("fun1()");
    }

    static void fun2() {
        System.out.println("fun2()");
    }

    void fun3();
}

public class J16 implements myInt {
    @Override
    public void fun3() {
        System.out.println("fun3()");
    }

    public static void main(String[] args) {
        J16 t = new J16();
        t.fun1();
        myInt.fun2();
        t.fun3();
    }
}
