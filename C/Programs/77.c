#include <stdio.h>

struct marks
{
    float m1;
    float m2;
    float m3;

};

struct dob
{
    int d;
    int m;
    int y;
};

struct time
{
int s;
int m;
int h;
}
struct student // new data type called student // int vs student
{
    char regno[10];
    char name[20];
    int age;
    float cgpa;
    struct marks m;
    struct dob d;
    struct time t;
    
};

int main()
{

    // array of structures
    struct student ksh[20];

    printf("\nEnter 2 students regno, name, age, and cgpa: ");

    for (int i = 0; i < 2; i++)
    {
        scanf("%s", ksh[i].regno);
        scanf("%s", ksh[i].name);
        scanf("%d", &ksh[i].age);
        scanf("%f", &ksh[i].cgpa);
        scanf("%f", &ksh[i].m.m1);
        scanf("%f", &ksh[i].m.m2);
        scanf("%f", &ksh[i].m.m3);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("\n%s", ksh[i].regno);
        printf("\n%s", ksh[i].name);
        printf("\n%d", ksh[i].age);
        printf("\n%f", ksh[i].cgpa);
        printf("\n%f", ksh[i].m.m1);
        printf("\n%f", ksh[i].m.m2);
        printf("\n%f", ksh[i].m.m3);
    }

    return 0;
}
