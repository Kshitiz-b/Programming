#include<stdio.h>
int factorial(int n){
	// n! = n*(n-1)
	if(n==0){
		return 1;
	}
	else
		 return n*factorial(n-1);
}
int main(void){
	// recursion
	printf("This is main function\n");
	int n;
	printf("Enter the integer: ");
	scanf("%d", &n);
	int result = factorial(n);
	
	printf("The factorial  of %d is: %d", n, result);
	

	return 0;
}
