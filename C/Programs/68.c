#include<stdio.h>
int main(){
	
	// Process Arrays using pointers
	int a[5];
	int i;
	
	printf("\nEnter 5 values:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\nEntered 5 values are: ");
	for(i=0;i<5;i++)
	{
		printf("%d ", a[i]);
	}
	
	int b[10];
	int *p;
	
	p = b;
	printf("\n\nEnter 5 values in b:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d", p);	// p = &b[0]
		p++;
	}
	p=b;
	printf("\nEntered 5 values in b:\n");
	for(i=0;i<5;i++)
	{
		printf("%d ", *p);	
		*p++;
	}
	
	
	return 0;
}