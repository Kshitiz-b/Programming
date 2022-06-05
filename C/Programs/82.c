#include <stdio.h>

struct complex
{
    float real;
    float imag;
};


void reading(struct complex c1, struct complex c2);

void addition(struct complex c1, struct complex c2, struct complex *result);

void subtraction(struct complex c1, struct complex c2, struct complex *result1);

void multiplication(struct complex c1, struct complex c2, struct complex *result2);

int main()
{
    
    struct complex c1;
    struct complex c2;
    struct complex result;
    struct complex result1;
    struct complex result2;
    
    printf("For first number:\n");
    printf("Enter the real part: ");
    scanf("%f", &c1.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c1.imag);

    printf("For second number:\n");
    printf("Enter the real part: ");
    scanf("%f", &c2.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &c2.imag);

    reading(c1, c2);

    addition(c1, c2, &result);
    printf("\nAddition = %f+i(%f)", result.real, result.imag);

    subtraction(c1, c2, &result1);
    printf("\nSubtraction = %f+i(%f)", result1.real, result1.imag);

    multiplication(c1, c2, &result2);
    printf("\nMultiplication = %f+i(%f)", result2.real, result2.imag);
    

    return 0;
}

void reading(struct complex c1, struct complex c2)
{
    printf("The first complex number is %f + i(%f)\n", c1.real, c1.imag);
    printf("The second complex number is %f + i(%f)\n", c2.real, c2.imag);
}

void addition(struct complex c1, struct complex c2, struct complex *result)
{
    result->real = c1.real + c2.real;
    result->imag = c1.imag + c2.imag;
}

void subtraction(struct complex c1, struct complex c2, struct complex *result1)
{
    result1->real = c1.real - c2.real;
    result1->imag = c1.imag - c2.imag;
}

void multiplication(struct complex c1, struct complex c2, struct complex *result2)
{
    result2->real = c1.real * c2.real;
    result2->imag = c1.imag * c2.imag;
}