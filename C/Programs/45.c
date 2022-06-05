#include<stdio.h>
	float subtraction(float, float); // global to program

int main(void){
	// Functions
	// task/funstion/method /routine - set of instructions to do particular tasks
    // calculator
	float a,b;
	float sum, diff, mul, div;
	float addition(float, float);	// function declaration
	
	float multiplication(float, float);
	float division(float, float);
    
    printf("Enetr two float values: \n");
    scanf("%f %f", &a, &b);
    
    sum = addition(a, b);	// calling or invoking of a function
    diff = subtraction(a, b);
	mul = multiplication(a, b);
	div = division(a, b);
	
	printf("The addition result is: %f\n", sum);
	printf("The subtraction result is: %f\n", diff);
	printf("The multiplication result is: %f\n", mul);
	printf("The division result is: %f\n", div);
	
	return 0;
}

float addition(float a, float b)	// function header
{
	float result;
	result = a+b;
	return result;
}

float subtraction(float a, float b)
{
	float result;
	result = a-b;
	return result;
}
float multiplication(float a, float b)
{
	float result;
	result = a*b;
	return result;
}
float division(float a, float b)
{
	float result;
	result = a/b;
	return result;
}
