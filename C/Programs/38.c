#include<stdio.h>
int main()
{
// Arrays and strings
// Arrays - what, why and how?
// Array - single variable we can hold more than one value - collection of values
float marks[5]; // marks[0], marks[1], marks[2], ...marks[109], n=0 to n-1
float sum=0, avg=0;
int i;

for(i=0;i<5;i++)
{
	scanf("%f", &marks[i]);
}

for(i=0;i<5;i++)
{
	printf("%f\n", marks[i]);
}

for(i=0;i<5;i++)
{
	sum = sum+marks[i];
}

avg = sum/5;
printf("The avg is: %f\n", avg);

return 0;
}
