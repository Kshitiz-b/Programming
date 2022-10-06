#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insertion(struct node *root, int x)
{
    if (root == NULL)
        return create(x);
    if (x < root->data)
        root->left = insertion(root->left, x);
    else
        root->right = insertion(root->right, x);
    return root;
}
struct node *subtreedelete(struct node *root, struct node *q)
{
    if (root->right != NULL)
        root->right = subtreedelete(root->right, q);
    else
    {
        q->data = root->data;
        root = root->left;
        free(root);
    }
    return (root);
}
struct node *deletion(struct node *root, int x)
{
    struct node *delnode;
    if (x < root->data)
        root->left = deletion(root->left, x);
    if (x > root->data)
        root->right = deletion(root->right, x);
    if (x == root->data)
    {
        delnode = root;
        if (delnode->right == NULL)
        {
            root = delnode->left;
            free(delnode);
        }
        if (delnode->left == NULL)
        {
            root = delnode->right;
            free(delnode);
        }
        if (delnode->left != NULL && delnode->right != NULL)
            delnode->left = subtreedelete(delnode->left, delnode);
    }
    return (root);
}
struct node *display(struct node *root, int level)
{
    int i;
    if (root)
    {
        display(root->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf(" ");
        printf("%d", root->data);
        display(root->left, level + 1);
    }
    
    return (0);
}
int main()
{
    struct node *root = NULL;
    int X, Y;
    char choice;
    // root = insertion(root, 45);
    // root = insertion(root, 30);
    // root = insertion(root, 50);
    // root = insertion(root, 25);
    // root = insertion(root, 35);
    // root = insertion(root, 45);
    // root = insertion(root, 60);
    // root = insertion(root, 4);
    printf("Binary Search Tree\n");
    // display(root, 1);
    // printf("\nDeleting node 25, Binary Search Tree\n");
    // deletion(root, 25);
    // display(root, 1);
    // printf("\nInserting node 2, Binary Search Tree\n");
    // insertion(root, 2);
    // display(root, 1);

    do
    {
        //printf("Enter your choice (i: Insertion, d: Deletion, p: Print)\n");
        scanf("%c", &choice);
        switch (choice)
        {
        case 'i':
            printf("Enter the element to Insert\n");
            scanf("%d", &X);
            root = insertion(root, X);
            display(root, 1);
            printf("\n");
            break;
        case 'd':
            printf("Enter the element you want to Delete\n");
            scanf("%d", &Y);
            deletion(root, Y);
            display(root, 1);
            printf("\n");
            break;
        case 'p':
            display(root, 1);
            printf("\n");
            break;
        }
    } while (choice != 'e');

    return 0;
}