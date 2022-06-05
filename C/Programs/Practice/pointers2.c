#include <stdio.h>
int main()
{
    double celsius, fahrenheit;
    double *p1 = &celsius, *p2 = &fahrenheit;

    printf("Enter degree Celsius: ");
    scanf("%lf", &celsius);

    
    
    fahrenheit = (9.0/5.0)*(*p1)+32;
    

    printf("%.2lf Fahrenheit", *p2);

    return 0;
}