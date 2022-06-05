#include<stdio.h>
float addition(float a[], float b)
{    
    int i;
    float sum=0;
    
    for(i=0;i<=4;i++)
    {
        sum=sum+a[i];
        a[i]++;
    }
    b++;
    return sum;
}
int main(void)
{
        float a[]={1,2,3,4,5};
        int i;
        float b=5;
    
    printf("Before calling \nb: %f\n", b);
    
    for(i=0;i<=4;i++)
    {
        printf("%f\t",a[i]);
    }

 

    printf("\nThe addition result is: %f\n\n",addition(a, b)); // calling a function by value
    
        
        printf("After calling \nb: %f\n", b);
    
    for(i=0;i<=4;i++)
    {
        printf("%f\t",a[i]);
    }
        
    return 0;    
}
