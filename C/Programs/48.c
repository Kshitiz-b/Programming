#include<stdio.h>
int main(void){
	
	// printf() and scanf() functions
	// format specifier
	// %d, %f ...
	
	float a = 234.454;
	
	printf("%f \n", a);
		printf("%.2f \n", a);
		printf("%5.2f \n", a);
		printf("%8.2f \n", a);
		printf("%8f \n", a);
		printf("%-8.2f \n", a);
	
	char b[]="university";
		printf("%.2s \n", b);
		printf("%5.2s \n", b);
		printf("%8.2s \n", b);
		printf("%8s \n", b);
		printf("%-8.2s \n", b);
	
	return 0;
	
}
