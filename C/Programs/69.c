#include<stdio.h>
#include<stdlib.h>

int main(){

	//	dynamic memory Allocation
	// <stdlib.h>
	// malloc() - memory allocation - ptr = (casting-ptr) malloc(size_bytes)
	// calloc() - contiguous allocation - ptr = (casting-ptr) caaloc(n, size of each element)
	// free() - de-allocate the memory - free(ptr)
	// realloc() - Re-allocate the memory - 

	// int a; a=5; scanf(), printf() - static

	int *p;
	
	p = (int*) malloc(1*sizeof(int));

	printf("\n Enter a value: ");
	scanf("%d", p);

	printf("\n Entered value is: %d", *p);

	free(p);

	return 0;
}