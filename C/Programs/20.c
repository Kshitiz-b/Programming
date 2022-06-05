#include<stdio.h>
#include<math.h>

int main(){

double investment, rate, value;
int years;
printf("Enter investment amount: ");
scanf("%lf", &investment);

printf("Enter monthly interest rate in percentage: ");
scanf("%lf", &rate);

printf("Enter number of years: ");
scanf("%d", &years);

rate = rate/100.0;
value = investment*(pow(1.0+rate, years));

printf("Accumulated value is %lf", value);

return 0;

}
