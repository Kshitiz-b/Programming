#include<stdio.h>
void addition(int n1, int n2, int results[])
{
	results[0] = n1+n2;
	results[1] = n1-n2;
	results[2] = n1*n2;
	results[3] = n1/n2;
}

int main(void){
	
	
	int n1=6, n2=10, results[10];
	addition(n1, n2, results);
	
	printf("The addition is: %d\n", results[0]);
	printf("The subrtaction is: %d\n", results[1]);
	printf("The multiplication is: %d\n", results[2]);
	printf("The division is: %d\n", results[3]);
	
	printf("The n1 is: %d\n", n1);
	printf("The n2 is: %d\n", n2);
	

	return 0;
}
