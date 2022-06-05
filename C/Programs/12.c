#include<stdio.h>

int main(){

double x, y;

printf("Enter the degree in Celsius: ");
scanf("%lf", &x);

y = ((9.0/5.0)*x)+32;

printf("%f Celsius is %f in Fahrenheit", x, y);
return 0;

}
