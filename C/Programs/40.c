#include<stdio.h>
#include<math.h>
#define size 5
int main()
{

    int i,j;
    float marks[size],sum,avg,min,max;

    printf(" Enter %d marks. \n");
    for (i=0;i<size;i++)
    {
        scanf("%f",&marks[i]);
        
    }

    min=marks[0];
    max=marks[0];

    for (j=0;j<size;j++)
    {
        sum+=marks[j];
        if(marks[j]<min)
        	min=marks[j];
        if(marks[j]>max)
        	max=marks[j];
    }

    printf(" Sum of the marks is : %f \n", sum);
    avg=sum/size;
    printf(" Average is : %f \n", avg);
    printf(" Least mark is : %f \n", min);
    printf(" Highest mark is : %f \n", max);

}
