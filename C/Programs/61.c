#include<stdio.h>
int addition(int n1, int n2){
	return n1+n2;
}
int main(void){
	// recursion
	
	int n1=5, n2=6;
	int result = addition(n1, n2);
	
	printf("The sum is: %d", result);
	

	return 0;
}
