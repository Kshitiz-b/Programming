#include <stdlib.h>
#include <stdio.h>

// ERROR
int main()
{
    int *arr;
    int i, j, m, n, sum=0;

    printf("Enter the number of rows:\n");
    scanf("%d", &m); 

    printf("Enter the number of columns:\n");
    scanf("%d", &n);

    arr = (int *) malloc(n * (sizeof(int)));

    printf("Enter %d values:\n", m*n);

    int *temp;
    temp = arr;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", arr);
            arr++;
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            
            sum = sum + *(arr + i);
            sum = sum + *(arr + j);
        }
    }
    arr = temp;

    printf("The sum is %d", sum);

    return 0;
}    