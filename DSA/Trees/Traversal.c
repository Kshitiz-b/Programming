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
    struct node *root = create(35);
    root->left = create(40);
    root->right = create(99);
    root->left->left = create(12);
    root->left->right = create(4);
    root->left->left->left = create(70);
    root->left->left->right = create(3);
    root->right->left = create(6);
    root->right->right = create(80);
    root->right->right->left = create(60);
    root->right->right->right = create(31);
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