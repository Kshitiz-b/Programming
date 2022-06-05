#include<stdio.h>

int main(){

double p, y;
const double kg=0.454;

printf("Enter a number in Pounds: ");
scanf("%lf", &p);

y = kg*p;

printf("%lf pounds is %lf in kilograms", p, y);
return 0;

}
