#include<stdio.h>
#define SIZE 5 	// pre-processor directive
int main()
{
float marks[SIZE];	// array - collection of same datatype values
float sum=0, avg=0;
int i, n;


for(i=0;i<SIZE;i++)
{
	scanf("%f", &marks[i]);
}
for(i=0;i<SIZE;i++)
{
	printf("%f\n", marks[i]);
}
for(i=0;i<SIZE;i++)
{
	sum = sum+marks[i];
}
avg = sum/SIZE;
printf("The avg is: %f\n", avg);


return 0;
}
