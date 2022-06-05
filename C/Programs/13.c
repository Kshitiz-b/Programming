#include<stdio.h>

int main(){

double x, y, z, a;

printf("Enter the subtotal: ");
scanf("%lf", &x);

printf("Enter the gratuity rates: ");
scanf("%lf", &y);

z = (y/100)*x;
a = x+z;

printf("The gratuity is $%f and total is $%f", z, a);
return 0;

}
