#include<stdio.h>

int main(){

// type casting
// implicit typecasting or automatic by compiler, explicit typecasting by programmer
// always do lower data type to higher data type

char ch='A'; // ASCII amereican standard code for information interchange - Numeric Number
int i=10;
float f=20.50;
double d = 35.5555;

double result = (ch/i) + (f*d) - (f+i);

printf("%lf\n", result);

printf("%d\n", (int)ch);

printf("%f", (float)6/5);
return 0;

}
