// creating node and printin the data
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

void print_data();

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    //printf("%d", head->data);
    struct node *current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 34;
    current->link = NULL;
    //printf("%d", current->data);
    head->link = current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 34;
    current->link = NULL;
    //printf("%d", current->data);
    head->link->link = current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 34;
    current->link = NULL;
    //printf("%d", current->data);
    head->link->link->link = current;
    print_data(head);
    return 0;
}

void print_data(struct node *head)
{

    if (head == NULL)
    {
        printf("Node is empty");
    }
    else
    {
        struct node *ptr;
        ptr = head;
        //ptr = NULL;
        printf("head->");
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->link;
        }
        printf("NULL");
    }
}