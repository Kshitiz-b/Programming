#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coefficient;
    int exponent;
    struct Node *next;
};
struct Node *list = NULL;

struct Node *insert(struct Node *list, int co, int ex)
{
    struct Node *temp;
    struct Node *newP = malloc(sizeof(struct Node));
    newP->coefficient = co;
    newP->exponent = ex;
    newP->next = NULL;
    if (list == NULL || ex > list->exponent)
    {
        newP->next = list;
        list = newP;
    }
    else
    {
        temp = list;
        while (temp->next != NULL && temp->next->exponent > ex)
            temp = temp->next;
        newP->next = temp->next;
        temp->next = newP;
    }
    return list;
}

void create()
{
    int n, i;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient for the term %d: ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the exponent for the term %d: ", i + 1);
        scanf("%d", &expo);
        list = insert(list, coeff, expo);
    }
}

void print()
{
    if (list == NULL)
        printf("No Polynomial.");
    else
    {
        struct Node *temp = list;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coefficient, temp->exponent);
            temp = temp->next;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

int main()
{
    create();
    print();

    return 0;
}
