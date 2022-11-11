public class Student {
    String name;

    public Student(String S) {
        name = S;
    }

    public Student() {
        name = "Unknown";
    }

    public static void main(String[] args) {

        Student S = new Student("Kshitiz");
        Student A = new Student();
        System.out.println("The name is: " + S.name);
        System.out.println("The name is: " + A.name);


    }

}