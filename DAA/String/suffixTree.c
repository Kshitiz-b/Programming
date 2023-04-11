#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in suffix tree
typedef struct SuffixTreeNode
{
    struct SuffixTreeNode **children;
    struct SuffixTreeNode *suffixLink;
    int start;
    int *end;
    int suffixIndex;
} SuffixTreeNode;

// Structure to represent a suffix tree
typedef struct SuffixTree
{
    SuffixTreeNode *root;
    int *suffixArray;
    int size;
} SuffixTree;

// Function to create a new node for suffix tree
SuffixTreeNode *createNewNode(int start, int *end)
{
    SuffixTreeNode *node = (SuffixTreeNode *)malloc(sizeof(SuffixTreeNode));
    node->children = (SuffixTreeNode **)malloc(sizeof(SuffixTreeNode *) * 256);
    for (int i = 0; i < 256; i++)
    {
        node->children[i] = NULL;
    }
    node->suffixLink = NULL;
    node->start = start;
    node->end = end;
    node->suffixIndex = -1;
    return node;
}

// Function to extend suffix tree with a new suffix
void extendSuffixTree(SuffixTreeNode **rootRef, SuffixTreeNode **lastRef, int *endRef, int index, char *text)
{
    int *splitEnd = (int *)malloc(sizeof(int));
    *endRef = index;
    SuffixTreeNode *last = NULL;
    while (index >= 0)
    {
        SuffixTreeNode *curr = *rootRef;
        if (*lastRef != NULL)
        {
            last = *lastRef;
        }
        while (index <= *endRef)
        {
            SuffixTreeNode *child = curr->children[text[index]];
            if (child == NULL)
            {
                curr->children[text[index]] = createNewNode(index, endRef);
                if (last != NULL)
                {
                    last->suffixLink = curr;
                }
                last = NULL;
            }
            else
            {
                int *childStart = child->start;
                if (doesSubstringMatch(text, childStart, child->end, index, endRef))
                {
                    if (last != NULL)
                    {
                        last->suffixLink = curr;
                    }
                    break;
                }
                else
                {
                    SuffixTreeNode *splitNode = createNewNode(child->start, childStart + (index - child->start) - 1);
                    curr->children[text[child->start]] = splitNode;
                    splitNode->children[text[index]] = createNewNode(index, endRef);
                    child->start += (index - child->start);
                    splitNode->children[text[child->start]] = child;
                    if (last != NULL)
                    {
                        last->suffixLink = splitNode;
                    }
                    last = splitNode;
                }
            }
            if (curr == *lastRef)
            {
                curr->suffixLink = last;
            }
            *lastRef = curr;
            if (index < *endRef)
            {
                curr = curr->children[text[++index]];
            }
        }
    }
    free(splitEnd);
}

// Function to build suffix tree for given text
SuffixTree *buildSuffixTree(char *text, int n)
{
    SuffixTreeNode *root = createNewNode(-1, NULL);
    SuffixTreeNode *last = NULL;
    int *end = (int *)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
    {
        extendSuffixTree(&root, &last, end, i, text);
    }
    SuffixTree *suffixTree = (SuffixTree *)malloc(sizeof(SuffixTree));
    suffixTree->root = root;
    suffixTree->size = n;
    suffixTree->suffixArray = (int *)malloc(sizeof(int) * n);
    getSuffArray(root, suffixTree->suffixArray, 0);
    free(end);
    return suffixTree;
}

// Function to compare two strings
int compareStrings(char *str1, int start1, int end1, char *str2, int start2, int end2)
{
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    int len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < len; i++)
    {
        if (str1[start1 + i] < str2[start2 + i])
        {
            return -1;
        }
        else if (str1[start1 + i] > str2[start2 + i])
        {
            return 1;
        }
    }
    if (len1 < len2)
    {
        return -1;
    }
    else if (len1 > len2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to search for pattern in suffix tree
void searchPatternInSuffixTree(SuffixTreeNode *root, char *text, char *pattern)
{
    int m = strlen(pattern);
    int n = strlen(text);
    SuffixTreeNode *curr = root;
    int i = 0;
    while (i < m)
    {
        SuffixTreeNode *child = curr->children[pattern[i]];
        if (child == NULL)
        {
            printf("Pattern not found\n");
            return;
        }
        else
        {
            if (compareStrings(text, child->start, *(child->end), pattern, i, i + *(child->end) - child->start) == 0)
            {
                printf("Pattern found at index %d\n", child->suffixIndex - m);
                return;
            }
            else
            {
                printf("Pattern not found\n");
                return;
            }
        }
    }
}

// Function to generate suffix array for given suffix tree
void getSuffArray(SuffixTreeNode *node, int *suffixArray, int idx)
{
    if (node == NULL)
    {
        return;
    }
    if (node->start != -1)
    {
        suffixArray[idx++] = node->suffixIndex;
    }
    for (int i = 0; i < 256; i++)
    {
        getSuffArray(node->children[i], suffixArray, idx);
    }
}

// Function to print suffix array
void printSuffixArray(int *suffixArray, int n)
{
    printf("Suffix Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", suffixArray[i]);
    }
    printf("\n");
}

int main()
{
    char text[100], pattern[100];
    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);
    SuffixTree *suffixTree = buildSuffixTree(text, strlen(text));
    searchPatternInSuffixTree(suffixTree->root, text, pattern);
    printSuffixArray(suffixTree->suffixArray, suffixTree->size);
    return 0;
}
