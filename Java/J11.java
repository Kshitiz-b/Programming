class Base {
    int x;

    Base() {
        x = 0;
    }

    Base(int i) {
        x = i;
    }
}

class Derived extends Base {
    int y;

    Derived() {
        super();
        y = 0;
    }

    Derived(int i, int j) {
        super(i);
        y = j;
    }
}

public class J11 {
    public static void main(String[] args) {
        Derived d = new Derived(10, 20);
        System.out.println(d.x);
        System.out.println(d.y);
    }
}
