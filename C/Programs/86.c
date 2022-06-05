#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date
{
    int dd, mm, yy;
};
struct Member
{
    char name[255], level[20], position[20];
    int clubID, Age;
    float amount_collected, amount_donated;
    struct date joining_date;
};
int year_diff(struct date date1, struct date date2)
{
    struct date difference;

    if (date2.dd >= date1.dd)
        difference.dd = date2.dd - date1.dd;
    else
    {
        date2.dd += 30;
        date2.mm -= 1;
        difference.dd = date2.dd - date1.dd;
    }
    if (date2.mm >= date1.mm)
        difference.mm = date2.mm - date1.mm;
    else
    {
        date2.mm += 12;
        date2.yy -= 1;
        difference.mm = date2.dd - date1.mm;
    }
    difference.yy = date2.yy - date1.yy;
    return difference.yy;
}
int main()

{

    struct date d1 = {1, 3, 2010};
    struct date d2 = {6, 10, 2013};
    struct date d3 = {17, 2, 2019};
    struct date current_dat = {17, 9, 2022};

    struct Member m1 = {.name = "m1", .level = "Diamond", .position = "treasurer", .clubID = 3, .Age = 46, .amount_collected = 200000.0, .amount_donated = 110000.0, .joining_date = d1};
    struct Member m2 = {.name = "m2", .level = "Gold", .position = "member", .clubID = 3, .Age = 36, .amount_collected = 60000.0, .amount_donated = 10000.0, .joining_date = d2};
    struct Member m3 = {.name = "m3", .level = "Silver", .position = "member", .clubID = 3, .Age = 36, .amount_collected = 60000.0, .amount_donated = 10000.0, .joining_date = d3};

    struct Member members[4] = {m1, m2, m3};
    for (int i = 0; i < 3; i++)
    {
        struct Member candidate = members[i];

        if ((strcmp(candidate.position, "treasurer") == 0 || strcmp(candidate.position, "secretary") == 0) && (candidate.amount_collected > 100000.0 || candidate.amount_donated > 100000.0) &&
            (strcmp(candidate.level, "Diamond") == 0))
            printf("%s is qualified for President\n", candidate.name);

        if (year_diff(candidate.joining_date, current_dat) > 4 && (candidate.amount_collected > 50000.0 || candidate.amount_donated > 50000.0))
            printf("%s is qualified for treasure\n", candidate.name);
        if (year_diff(candidate.joining_date, current_dat) > 1 && strcmp(candidate.level, "Silver") == 0)
            printf("%s is qualified for secretary\n", candidate.name);
    }

    return 0;
}