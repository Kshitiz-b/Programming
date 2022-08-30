#include <stdio.h>

int main()
{
    int A[8] = {15, 5, 20, 35, 2, 42, 67, 17};
    int T, index;

    printf("Enter the target element: ");
    scanf("%d", &T);

    for (int i = 0; i < 8; i++)
    {
        if (A[i] != T)
            index = -1;
        else
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        printf("Element is not present\n");
    else
        printf("The index of the Target Element is: %d", index);

    return 0;
}