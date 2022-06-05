#include <stdio.h>

// user (programmer) - defined data type
struct student // new data type called student // int vs student
{
    char regno[10];
    char name[20];
    int age;
    float cgpa;
}ksh4, ksh5 = {"21bcb2043", "pappu", 25, 1};

int main()
{

    struct student ksh1, ksh2;
    printf("\n the size of student data type is %d", sizeof(ksh1));

    // read and display values
    // to access members of structure - Member operator (.) / dot

    printf("\nEnter regno, name, age, and cgpa: ");
    scanf("%s", ksh1.regno);
    scanf("%s", ksh1.name);
    scanf("%d", &ksh1.age);
    scanf("%f", &ksh1.cgpa);

    printf("\nEntered values ");
    printf("\n%s", ksh1.regno);
    printf("\n%s", ksh1.name);
    printf("\n%d", ksh1.age);
    printf("\n%f", ksh1.cgpa);



    strcpy(ksh2.regno, "21BCE2067");
    strcpy(ksh2.name, "KSHITIZ");
    ksh2.age = 18;
    ksh2.cgpa = 9.1;
    printf("\n");
    printf("\nksh2 details: ");
    printf("\n%s", ksh2.regno);
    printf("\n%s", ksh2.name);
    printf("\n%d", ksh2.age);
    printf("\n%f", ksh2.cgpa);

    struct student ksh3 = { "21bbc2065", "rejesh", 18, 5};
    printf("\nEntered ksh3 details are:");
    printf("\n%s", ksh3.regno);
    printf("\n%s", ksh3.name);
    printf("\n%d", ksh3.age);
    printf("\n%f", ksh3.cgpa);

    // assignment operator works for structures also if they are same data type

    ksh4 = ksh3;
    printf("\nEntered ksh4 details are:");
    printf("\n%s", ksh4.regno);
    printf("\n%s", ksh4.name);
    printf("\n%d", ksh4.age);
    printf("\n%f", ksh4.cgpa);

    printf("\nEntered ksh5 details are:");
    printf("\n%s", ksh5.regno);
    printf("\n%s", ksh5.name);
    printf("\n%d", ksh5.age);
    printf("\n%f", ksh5.cgpa);

    return 0;
}