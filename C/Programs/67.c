#include<stdio.h>
int main(){
	
	float a=5;
    
    int *p1; // data type meaning - it is pointing the variable of the data type
    float *p2;
    p1=&a; // not valid
   
    p2 = &a; // valid
	
	return 0;
}