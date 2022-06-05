#include<stdio.h>
#include<stdlib.h>

int main(){

    // Mutiple integer values - Single dimentional array

    int *p;
    int n, i;

    printf("\n Enter n: ");
	scanf("%d", &n);

    p = (int*) malloc(n*sizeof(int));

    printf("\n Enter %d values: \n", n);

    for(i=0;i<n;i++){
	    scanf("%d", p+i);
    }
    

    printf("\n Entered values are: ");

    for(i=0;i<n;i++){
	    printf("%d ", *(p+i));
    }

	return 0;
}