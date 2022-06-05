#include<stdio.h>
float addition(float c, float d)
{    
c++;
d++;
    return c+d;
    
}
int main(void)
{
        float a, b;
    printf("Enter two float values:\n");
    scanf("%f %f",&a,&b); 
    
    printf("Before calling: %f \t %f \n", a,b);

 

    printf("The addition result is: %f\n",addition(a,b)); // calling a function by value
    
        printf("After calling: %f \t %f \n", a,b);
    return 0;    
}
