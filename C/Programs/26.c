#include<stdio.h> 
int main(){ 

double balance, rate, interest;
printf("Enter balance and interest rate:");
scanf("%lf %lf", &balance, &rate);

interest = balance*(rate/1200.0);
printf("The interest is %lf", interest);

return 0;
        
}
