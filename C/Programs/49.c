#include<stdio.h>
int main(void){
	int row = 2, col = 2;
	double matrix1[row][col], matrix2[row][col];
	double sum[row][col], product[row][col], sub[row][col];
	int i, j, k;
	// entering values
	printf("Enter the values of matrix1 2x2: \n");
	
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			scanf("%lf", &matrix1[i][j]);	
		}	
	}
	
	printf("Enter the values of matrix2 2x2: \n");
	
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			scanf("%lf", &matrix2[i][j]);	
		}	
	}
	// printing matrix 1 and 2
	printf("Matrix1 is:\n");
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			printf("%lf\t", matrix1[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
	
	printf("Matrix2 is:\n");
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			printf("%lf\t", matrix2[i][j]);	
		}	
		printf("\n");
	}
	printf("\n");
	
	// Addition
	printf("Addition of Matrix1 and Matrix2 is: \n");
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			sum[i][j] = matrix1[i][j] + matrix2[i][j];
		}	
	}
	
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			printf("%lf\t", sum[i][j]);	
		}	
		printf("\n");
	}
	printf("\n");
	
	// Subtraction
	printf("Subtraction of Matrix1 and Matrix2 is: \n");
	
	for(i=0; i<row; i++){
		for(j=0; j<col; j++){
			sub[i][j] = matrix1[i][j] - matrix2[i][j];
		}	
	}
	
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			printf("%lf\t", sub[i][j]);	
		}	
		printf("\n");
	}
	printf("\n");
	
	// Multiplication
	printf("Multiplicaiton of Matrix1 and Matrix2 is: \n");
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			product[i][j] = 0;
		}
	}
	
	// multiplying and storing result in product[][]
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			for(k=0;k<col;k++){
				product[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	
	for(i=0;i<row;i++){
		for(j=0; j<col; j++){
			printf("%lf\t", product[i][j]);	
		}	
		printf("\n");
	}
	printf("\n");
	
	return 0;
	
}
