// Binary Search using recursion
#include <stdio.h>

int binarySearch(int arr[], int T, int l, int r)
{
    if (r >= l)
    {
        int mid = (l+r)/2;

        if (arr[mid] == T)
            return mid;
        else if (arr[mid] > T)
        {
            return binarySearch(arr, T, l, (mid-1));
        }
        else
        {
            return binarySearch(arr, T, (mid+1), r);
        }
    }
    return -1;
}

int main(void)
{

    int arr[] = {5, 9, 17, 23, 25, 45, 59, 63, 71, 89};
    int T, l, r;


    printf("Enter the target element: ");
    scanf("%d", &T);

    int result = binarySearch(arr, T, 0, 9);

    if (result == -1)
        printf("Element not found\n");
    else 
        printf("Element is at Index: %d", result);

    return 0;
}