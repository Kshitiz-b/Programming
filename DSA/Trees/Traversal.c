#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
/*To create a new node*/
struct node *create(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}
/*function to traverse the nodes of binary tree in Inorder*/
void traverseInorder(struct node *root)
{
    if (root == NULL)
        return;
    traverseInorder(root->left);
    printf(" %d ", root->data);
    traverseInorder(root->right);
}
void traversePostorder(struct node *root)
{
    if (root == NULL)
        return;
    traversePostorder(root->left);
    traversePostorder(root->right);
    printf(" %d ", root->data);
}
void printLeaf(struct node *root)
{
    if (root == NULL)
        return;
    printLeaf(root->left);
    printLeaf(root->right);
    if (root->right == NULL && root->left == NULL)
        printf(" %d ", root->data);
}
void traversePreorder(struct node *root)
{
    if (root == NULL)
        return;
    printf(" %d ", root->data);
    traversePreorder(root->left);
    traversePreorder(root->right);
}
int main()
{
    struct node *root = create(40);
    root->left = create(30);
    root->right = create(50);
    root->left->left = create(25);
    root->left->right = create(35);
    root->left->left->left = create(15);
    root->left->left->right = create(28);
    root->right->left = create(45);
    root->right->right = create(60);
    root->right->right->left = create(55);
    root->right->right->right = create(70);
    printf("\n The Inorder traversal of given binary tree is -\n");
    traverseInorder(root);
    printf("\n The Postorder traversal of given binary tree is-\n");
    traversePostorder(root);
    printf("\n The Preorder traversal of given binary tree is-\n");
    traversePreorder(root);
    printf("\n The Leaf Nodes are-\n");
    printLeaf(root);
    return 0;
}