#include <stdio.h>

void BubbleSort(int A[], int n)
{
    int i, j, temp, num = 0;

    for (i = 0; i < (n - 1); i++)
    {
        int flag = 0;
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        num++;
        if (flag == 0)
            break;
    }
    printf("The number of Passes: %d\n", num);
}

void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int A[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    BubbleSort(A, n);
    printf("The Sorted Array is:\n");
    Display(A, n);

    return 0;
}