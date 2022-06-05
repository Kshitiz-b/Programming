#include <stdio.h>

struct student
{
    char name[20];
    int age;
};

struct student display(struct student temp)
{
    // -> operator used to access members of a structure using its pointer
    strcpy(temp.name, "raja");
    temp.age = 46;

    return temp;
}

int main()
{

    struct student naga = {"nagarja", 34};

    printf("\n The student details before function call: ");
    printf("\n%s", naga.name);
    printf("\n%d", naga.age);

    struct student naga2 = display(naga);

    printf("\n The student naga details after function call: ");
    printf("\n%s", naga.name);
    printf("\n%d", naga.age);

    printf("\n The student naga2 details after function call: ");
    printf("\n%s", naga2.name);
    printf("\n%d", naga2.age);

    return 0;
}