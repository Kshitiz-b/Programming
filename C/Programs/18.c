#include<stdio.h>
#include<math.h>

int main(){

double temp, speed, index;

printf("Enter the temperature in Fahrenheit between -58F and 41F: ");
scanf("%lf", &temp);

printf("Enter the wind speed (>=2) in miles per hour: ");
scanf("%lf", &speed);

index = 35.74 + 0.6215*temp - 35.75*pow(speed, 0.16) + 0.427*temp*pow(speed, 0.16);

printf("The wind chill index is %0.5lf", index);

return 0;

}
