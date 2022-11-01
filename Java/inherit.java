import java.util.*;

class person {
    String name;
    String code;
}

class account extends person {
    double pay;
}

interface admin {
    int experience = 0;
}

class master extends account implements admin {
    master(String n, String c, double p) {
        name = n;
        code = c;
        pay = p;
    }

    void display() {
        System.out.println(name + "\n" + code + "\n" + pay + "\n");
    }
}

public class inherit {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter data: ");
            String n = sc.nextLine();
            String c = sc.nextLine();
            double p = sc.nextDouble();
            master m = new master(n, c, p);
            m.display();
        }
    }
}