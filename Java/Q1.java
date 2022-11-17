class Patient {
    int n;
    float wt;
    float avgWt;

    Patient() {
        n = 10;
        wt = 60*n;
        avgWt = wt/n;
    }

    Patient(int ni, int wi) {
        Patient p = new Patient();
        n = p.n+ni;
        wt = p.wt + (ni*wi);
        avgWt = wt/n;
    }

    void total() {
        System.out.println("The total patients are: " + n);
        System.out.println("The total weight is: " + wt);
        System.out.println("The avg weight is: " + avgWt + "\n");
    }
}
    

public class Q1
{
    public static void main(String[] args) {
        Patient p1 = new Patient();
        Patient p2 = new Patient(5, 10);

        p1.total();
        p2.total();
    }
}