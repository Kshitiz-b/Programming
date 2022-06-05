#include<stdio.h>
int main(){
	
	// pointers
	// variables
	
	int a=5;
	int b=20;
	printf("\nThe address of a is: %u", &a);
	printf("\nThe value of a is: %d", a);
	
	printf("\nThe address of b is: %u", &b);
	printf("\nThe value of b is: %d\n", b);
	
	int *p1, *p2;	// pointer variables - p1 and p2
	
	p1 = &a;
	p2 = &b;
	
	printf("\nThe p1 is: %u", p1);
	printf("\nThe p2 is: %u", p2);
	
	printf("\nThe value of a using pointer is: %u", *p1);
	printf("\nThe value of b using pointer is: %u", *p2);
	
	int sum, *psum;
	
	sum = a+b;
	printf("\n\nThe sum using variables is: %d", sum);
	
	psum = &sum;
	*psum = (*p1) + (*p2);
	
	printf("\nThe sum using pointer variables is: %d", *psum);
	
	return 0;
}