#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function used in Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized partition function used in Quick Sort
int randomized_partition(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

// Randomized Quick Sort function
void randomized_quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = randomized_partition(arr, low, high);
        randomized_quick_sort(arr, low, pi - 1);
        randomized_quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Read the elements from input
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array using randomized Quick Sort
    randomized_quick_sort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
