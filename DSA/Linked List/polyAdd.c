#include <stdio.h>
#include <stdlib.h>

struct Node
{
    float coefficient;
    int exponent;
    struct Node *next;
};
struct Node *list1 = NULL;
struct Node *list2 = NULL;

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

struct Node *create(struct Node *list)
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
    return list;
}

void print(struct Node *list)
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

void polyAdd(struct Node *list1, struct Node *list2)
{
    struct Node *ptr1 = list1;
    struct Node *ptr2 = list2;
    struct Node *list3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent == ptr2->exponent)
        {
            list3 = insert(list3, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->exponent > ptr2->exponent)
        {
            list3 = insert(list3, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent)
        {
            list3 = insert(list3, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        list3 = insert(list3, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        list3 = insert(list3, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    printf("Added Polynomials is: ");
    print(list3);
}

int main()
{
    printf("Enter the first Polynomial\n");
    list1 = create(list1);
    printf("Enter the second Polynomial\n");
    list2 = create(list2);
    print(list1);
    print(list2);

    polyAdd(list1, list2);

    return 0;
}