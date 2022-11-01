public class weights {
    int wts[];

    weights() {
        wts = new int[10];
        for (int i = 0; i < 10; i++)
            wts[i] = 60;
    }

    weights(int ni, int wi) {
        wts = new int[ni];
        for (int i = 0; i < ni; i++)
            wts[i] = 60 + wi;
    }

    void update(int i, int wt) {
        wts[i] = wt;
    }

    double average() {
        double av = 0;
        for (int i = 0; i < wts.length; i++)
            av += wts[i];
        av /= wts.length;
        return av;
    }

    public static void main(String[] args) {
        weights w1 = new weights();
        weights w2 = new weights(5, 10);
        double av1 = w1.average();
        double av2 = w2.average();
        System.out.println(av1 + "\n" + av2);
    }
}