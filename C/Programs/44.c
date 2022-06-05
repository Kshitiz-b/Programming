#include<stdio.h>
#define row 4	
#define col 4
int main(){
	int matrix[row][col];
	double sum=0;
	int i, j;
	printf("Enter a 4-by-4 matrix row by row:\n");
	
   for (i = 0; i < row; i++) 
   {
      for (j = 0; j < col; j++) 
	  {
         scanf("%d", &matrix[i][j]);
      }
   }
	
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < col; j++) 
    	{
     		if (i == j)
     			sum = sum + matrix[i][j];
    	}
	}
	printf("\nSum of Diagonal Elements in Matrix is: %lf", sum);
	
	
	return 0;
}
