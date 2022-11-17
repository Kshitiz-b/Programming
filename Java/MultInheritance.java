class Person {
    int PersonID;
    String PersonName;
    String Gender;
    String DOB;
    String Country;

    void getData(int id, String na, String gen, String dob, String cou) {
        PersonID = id;
        PersonName = na;
        Gender = gen;
        DOB = dob;
        Country = cou;
    }

    void putData() {
        System.out.println(PersonID + "\n" + PersonName + "\n" + Gender + "\n" + DOB + "\n" + Country);
    }
}

class Student extends Person {
    int Roll;
    String CourseName;
    int FeesPaid;
    int Subjects;

    void getData(int no, String na, int fee, int sub) {
        Roll = no;
        CourseName = na;
        FeesPaid = fee;
        Subjects = sub;
    }

    void putData() {
        System.out.println(Roll + "\n" + CourseName + "\n" + FeesPaid + "\n" + Subjects);
    }
}

class Employee extends Student {
    int EmpID;
    String Designation;
    int Salary;

    void getData(int id, String des, int sal) {
        EmpID = id;
        Designation = des;
        Salary = sal;
    }

    void putData() {
        System.out.println(EmpID + "\n" + Designation + "\n" + Salary);
    }
}

public class MultInheritance {
    public static void main(String[] args) {

        Person p1 = new Person();
        p1.getData(123, "Person1", "Male", "10/02/2000", "India");
        Student s1 = new Student();
        s1.getData(5281, "Mechanical Engineering", 500000, 6);
        Employee e1 = new Employee();
        e1.getData(123, "Mechanic", 12000);

        Person p2 = new Person();
        p2.getData(456, "Person2", "Female", "18/04/2001", "India");
        Student s2 = new Student();
        s2.getData(7346, "Software Engineering", 1000000, 8);
        Employee e2 = new Employee();
        e2.getData(456, "Software Engineer", 50000);

        Person p3 = new Person();
        p3.getData(789, "Person3", "Female", "20/10/2000", "India");
        Student s3 = new Student();
        s3.getData(6829, "Mechanical Engineering", 500000, 6);
        Employee e3 = new Employee();
        e3.getData(789, "Mechanic", 15000);

        totalSalary(p1, p2, p3, e1, e2, e3);
        Display(p1, p2, p3, e1, e2, e3);
        HighSal(p1, p2, p3, s1, s2, s3, e1, e2, e3);
    }

    public static void totalSalary(Person p1, Person p2, Person p3, Employee e1, Employee e2, Employee e3) {
        int totalSal = 0;
        if (p1.Gender.equals("Female"))
            totalSal += e1.Salary;
        if (p2.Gender.equals("Female"))
            totalSal += e2.Salary;
        if (p3.Gender.equals("Female"))
            totalSal += e3.Salary;

        System.out.println("The total Salary of all the Female Employees is " + totalSal + "\n");

    }

    public static void Display(Person p1, Person p2, Person p3, Employee e1, Employee e2, Employee e3) {
        if (e1.Designation.equals("Mechanic"))
            System.out.println("Person name who is Mechanic: " + p1.PersonName + "\nDOB is " + p1.DOB + "\n");
        if (e2.Designation.equals("Mechanic"))
            System.out.println("Person name who is Mechanic: " + p2.PersonName + "\nDOB is " + p2.DOB + "\n");
        if (e3.Designation.equals("Mechanic"))
            System.out.println("Person name who is Mechanic: " + p3.PersonName + "\nDOB is " + p3.DOB + "\n");
    }

    public static void HighSal(Person p1, Person p2, Person p3, Student s1, Student s2, Student s3, Employee e1,
                               Employee e2, Employee e3) {
        if (e1.Salary > e2.Salary && e1.Salary > e3.Salary)
            System.out.println(
                    "The Person having highest salary is " + p1.PersonName + "\nAnd Course is " + s1.CourseName);
        else if (e2.Salary > e3.Salary && e2.Salary > e1.Salary)
            System.out.println(
                    "The Person having highest salary is " + p2.PersonName + "\nAnd Course is " + s2.CourseName);
        else if (e3.Salary > e1.Salary && e3.Salary > e2.Salary)
            System.out.println(
                    "The Person having highest salary is " + p3.PersonName + "\nAnd Course is " + s3.CourseName);
    }
}
