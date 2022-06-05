#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, D, r1, r2;
    double *p1 = &a, *p2 = &b, *p3 = &c, *p4 = &r1, *p5 = &r2;

    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &*p1, &*p2, &*p3);

    D = ((b * b) - 4.0* a * c);

    if (D > 0)
    {
        *p4 = (-(b) + pow(D, 0.5))/2*a;
        *p5 = (-(b) - pow(D, 0.5))/2*a;

        printf("The roots are %lf and %lf", *p4, *p5);
    }

    else if (D<0)
    {
        printf("The equation has no real roots");
    }

    else
    {
        *p4 = (-(b) + pow(D, 0.5))/2*a;
        printf("The root is %lf", *p4);
    }

    
    return 0;
}