public class Holiday {
    private String name;
    private int day;
    private String month;

    public Holiday(String n, int d, String m) {
        name = n;
        day = d;
        month = m;
    }

    String getName() {
        return name;
    }

    String getMonth() {
        return month;
    }

    int getDay() {
        return day;
    }

    public static boolean inSameMonth(Holiday h1, Holiday h2) {
        return h1.getMonth().equals(h2.getMonth());
    }

    public static double avgDate(Holiday[] arr) {
        double avg = 0;

        for (int i = 0; i < arr.length; i++) {
            avg = avg + arr[i].getDay();
        }
        return avg / arr.length;
    }

    public static void main(String[] args) {
        Holiday h1 = new Holiday("Independence Day", 4, "July");
        Holiday h2 = new Holiday("Raksha Bandhan", 10, "July");

        Holiday[] arr = new Holiday[2];
        arr[0] = h1;
        arr[1] = h2;

        System.out.println(inSameMonth(h1, h2));
        System.out.println(avgDate(arr));

    }
}