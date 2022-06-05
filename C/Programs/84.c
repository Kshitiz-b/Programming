#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Internal_marks
{
    float cat1;
    float cat2;
};
struct external_marks
{
    float viva;
    float fat;
};
struct Examination
{
    char regno[20];
    char dregno[20];
    char name[40];
    struct Internal_marks internal;
    struct external_marks external;
} ob[100];
void display(int i)
{
    int j = 0;
    for (j = 0; j < i; j++)
    {
        printf("student%d details:\n", j + 1);
        printf("regno=%s\n", ob[j].regno);
        printf("name=%s\n", ob[j].name);
        printf("cat1=%f\n", ob[j].internal.cat1);
        printf("cat2=%f\n", ob[j].internal.cat2);
        printf("viva=%f\n", ob[j].external.viva);
        printf("fat=%f\n", ob[j].external.fat);
    }
}
void ascending(int i)
{
    float total[i];
    char temp[20];
    int j, k;
    for (j = 0; j < i; j++)
    {
        total[j] = ob[j].internal.cat1 + ob[j].internal.cat2 + ob[j].external.viva + ob[j].external.fat;
        strcpy(ob[j].dregno, ob[j].regno);
    }
    for (j = 0; j < i; j++)
    {
        for (k = 0; k < i - j - 1; k++)
        {
            if (total[k] > total[k + 1])
            {
                strcpy(temp, ob[k + 1].dregno);
                strcpy(ob[k + 1].dregno, ob[k].dregno);
                strcpy(ob[k].dregno, temp);
            }
        }
    }
    printf("\nregister no's based on total marks:");
    for (j = 0; j < i; j++)
    {
        printf("\nregno%d=%s", j + 1, ob[j].dregno);
    }
}
void average(int i)
{
    float average_internal = 0;
    float average_external = 0;
    int j = 0;
    for (j = 0; j < i; j++)
    {
        average_internal = average_internal + ob[j].internal.cat1 + ob[j].internal.cat2;
        average_external = average_external + ob[j].external.viva + ob[j].external.fat;
    }
    printf("total average internal marks=%f", average_internal / i);
    printf("\ntotal average external marks=%f", average_external / i);
}
void name_display(char *reg, int i)
{
    int j;
    for (j = 0; j < i; j++)
    {
        if (strcmp(ob[j].regno, reg) == 0)
        {
            printf("name=%s", ob[j].name);
            break;
        }
    }
    if (j == i)
        printf("enter correct regno");
}
int main()
{
    int n, i;
    char regno[20];
    printf("enter Number of Students:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the register number:");
        scanf("%s", ob[i].regno);
        printf("enter the student name:");
        scanf("%s", ob[i].name);
        printf("enter the marks of cat1:");
        scanf("%f", &ob[i].internal.cat1);
        printf("enter the marks of cat2:");
        scanf("%f", &ob[i].internal.cat2);
        printf("enter the marks of viva:");
        scanf("%f", &ob[i].external.viva);
        printf("enter the marks of fat:");
        scanf("%f", &ob[i].external.fat);
    }
    display(i);
    average(i);
    ascending(i);
    printf("\nenter regno:");
    scanf("%s", regno);
    name_display(regno, i);
    
    return 0;
}