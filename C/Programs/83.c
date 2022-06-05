#include <stdio.h>

struct employees
{
    char name[20];
    int id;
    float salary;
};

int main()
{
    struct employees employee;

    printf("Enter employee's name, id and salary:\n");

    scanf("%s", employee.name);
    scanf("%d", &employee.id);
    scanf("%f", &employee.salary);

    printf("%s\n", employee.name);
    printf("%d\n", employee.id);
    printf("%f\n", employee.salary);

    return 0;
}