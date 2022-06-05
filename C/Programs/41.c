#include<stdio.h>
#define size1 2	// 2 students
#define size2 3	// 3 subjects
int main()
{
    int i,j;
    float marks[size1][size2];

    printf(" Enter %d marks: \n", size1*size2);
    for (i=0;i<size1;i++)
    {
    	for (j=0;j<size2;j++){
    		scanf("%f", &marks[i][j]);
		}
        	
    }
	
	printf("The entered values are: \n");
	
	for (i=0;i<size1;i++)
    {
    	for (j=0;j<size2;j++){
    		printf("%f\t", marks[i][j]);
		}
        	printf("\n");
    }

    
    return 0;

}
