#include<stdio.h>

int main(){

int min;

printf("Enter the number of minutes: ");
scanf("%d", &min);

int years = min/525600;
int days = (min%525600)/1440;

printf("%d minutes is approx %d in years and %d days", min, years, days);
return 0;

}
