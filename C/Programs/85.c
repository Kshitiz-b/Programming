#include <stdio.h>

struct doj
{
    int date;
    int month;
    int year;
};
struct club
{
    char name[20];
    int id;
    struct doj d;
    float collected;
    float donated;
    char level[20];
    char position[20]
};


int main()
{
    struct club member;
    printf("Enter the name id doj(dd mm yy) amount collected/donated and level and position\n");

    scanf("%s", member.name);
    scanf("%d", &member.id);
    scanf("%d", &member.d.date);
    scanf("%d", &member.d.month);
    scanf("%d", &member.d.year);
    scanf("%f", &member.collected);
    scanf("%f", &member.donated);
    scanf("%s", member.level);
    scanf("%s", member.position);

    printf("%s", member.name);
    printf("%d", member.id);
    printf("%d", member.d.date);
    printf("%d", member.d.month);
    printf("%d", member.d.year);
    printf("%f", member.collected);
    printf("%f", member.donated);
    printf("%s", member.level);
    printf("%s", member.position);

    if (member.position == secratory || assistant) && (member.collected + member.donated >= 100000) && (member.level == diamond)
    {
        printf("This member is eligible to run for the president.\n")
    }

    return 0;
}