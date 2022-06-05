#include<stdio.h>
#include<math.h>
int main(){
	// fundamental/primitive/primary
	// int, float, double, char, _Bool = 0/1, C99
	
	int a=10;
	float b=34.56;
	double c=34.56789;
	char d='4';
	/*
	1-bit - 0/1
	2-bit - 00/01/10/11
	3-bit - 
	4-bytes - 32-bits
	*/
	
	// signed vs unsigned - both positive and negative - int a = signed int a
	// sizeof() - operator // no. of bytes - 8 bits
	
	
	printf("%d	%d	%d	%d", sizeof(int), sizeof(b), sizeof(c), sizeof(d));
	/*
	4 4 8 1
	
	compiler and machine(Processor)
	
	bits 
	
	signed = +- = 1-bit
	7 bits = -127 to 128
	
	unsigned = 8 bits
	*/
}
