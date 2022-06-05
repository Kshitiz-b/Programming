#include <stdio.h>
int main()
{
    
    double interest, balance, annualInterest;
    double *p1 = &interest, *p2 = &balance, *p3 = &annualInterest;
    printf("Enter balance and interest rate: ");
    scanf("%lf %lf", &*p2, &*p3);

    *p1 = (*p2)*((*p3)/1200);
    printf("The interest is %lf", *p1);
    return 0;
}