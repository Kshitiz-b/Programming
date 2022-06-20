// NOT WORKING
#include <iostream>
using namespace std;

void read(int y, int z)
{
    int arr[y][z];

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < z; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int m, n;

    printf("Enter m, n:\n");
    scanf("%d %d", m, n);

    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    read(m, n);

    return 0;
}