#include<stdio.h>
int main(void){
	char number[20] = "2022";
	
	// "2" - string = 2 - it is possible 
	// 2 - integer
	// '2' - character
	// 2.0 - float/double
	// "a" = equivalent integer is not possible
	
	int n = atoi(number);
	printf("The integer is: %d\n", n);
	
	return 0;
}
