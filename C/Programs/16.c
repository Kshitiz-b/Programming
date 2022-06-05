#include<stdio.h>

int main(){

double v, a, l;

printf("Enter the speed and accelaration: ");
scanf("%lf %lf", &v, &a);

l = (v*v)/(2.0*a);

printf("The minimum runway length is %lf", l);
return 0;

}
