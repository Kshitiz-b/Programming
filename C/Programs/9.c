#include<stdio.h>

int main(){
// declaration - it will assign the memory for the variables
char ch;
int i;
float f;
double d;

printf("Enter a character: ");
scanf("%c", &ch); // & operator address
printf("Enter a integer: ");
scanf("%d", &i);
printf("Enter a float: ");
scanf("%f", &f);
printf("Enter a double: ");
scanf("%lf", &d);

printf("The character is %c\n", ch);
printf("The integer is %d\n", i);
printf("The float is %f\n", f);
printf("The double is %lf\n", d);	

return 0;

}
