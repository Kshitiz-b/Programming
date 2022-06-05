#include<stdio.h>

int main(){

double savings, first, second, third, fourth, fifth, sixth;
const double rate = 0.00417;

printf("Enter the monthly savings amount: ");
scanf("%lf", &savings);

first = savings*(1 + rate);
second = (savings+first)*(1+rate);
third = (savings+second)*(1+rate);
fourth = (savings+third)*(1+rate);
fifth = (savings+fourth)*(1+rate);
sixth = (savings+fifth)*(1+rate);


printf("After sixth month, the account value is $%.2lf", sixth);
return 0;

}
