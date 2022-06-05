int main()
{
    int *p;
    int *q;
    int i, n;

    printf("Enter n: ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("\nEnter %d values: ", n);


    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    q = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        *(q + i) = *(p + i);
    }

    printf("\nEntered values in q are: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(q + i));
    }

    return 0;
}