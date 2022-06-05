#include<stdio.h>

int main(){

int x;

printf("Enter the integer: ");
scanf("%d", &x);

x = (x%2==0) ? printf("Even Number") : printf("Odd Number") ;

return 0;

}
