#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    char DATA;
    struct Node *Left;
    struct Node *Right;
} NODE;
typedef struct tree
{
    NODE *root;
} TREE;
NODE *createNODE(char c)
{
    NODE *New = malloc(sizeof(NODE));
    New->DATA = c;
    New->Left = NULL;
    New->Right = NULL;
    return New;
}
TREE *createTREE()
{
    TREE *newt = malloc(sizeof(TREE));
    newt->root = NULL;
    return newt;
}
// pure recursion DFS(depth-first-serch)
void insert(NODE **t, char c)
{
    if (*t == NULL)
    {
        *t = createNODE(c);
        printf("done\n");
        return;
    }
    if ((*t)->Left == NULL)
        insert(&(*t)->Left, c);
    else
        insert(&(*t)->Right, c);
}
void FindLevel(NODE *root, char c, int level)
{
    if (!root)
        return;
    if (root->DATA == c)
    {
        printf("the level of the node %c is: %d\n", c, level);
        return;
    }
    FindLevel(root->Left, c, level + 1);
    FindLevel(root->Right, c, level + 1);
}
void preorder(NODE *t)
{
    // R G D
    if (!t)
        return;
    printf("%c   ", t->DATA);
    preorder(t->Left);
    preorder(t->Right);
}
void inorder(NODE *t)
{
    // G R D
    if (!t)
        return;
    inorder(t->Left);
    printf("%c   ", t->DATA);
    inorder(t->Right);
}
void postorder(NODE *t)
{
    // G D R
    if (!t)
        return;
    postorder(t->Left);
    postorder(t->Right);
    printf("%c   ", t->DATA);
}
int main()
{
    TREE *tr = createTREE();
    insert(&tr->root, 'A');
    FindLevel(tr->root, 'A', 0);
    insert(&tr->root, 'B');
    FindLevel(tr->root, 'B', 0);
    insert(&tr->root, 'C');
    FindLevel(tr->root, 'C', 0);
    insert(&tr->root, 'D');
    FindLevel(tr->root, 'D', 0);
    insert(&tr->root, 'E');
    FindLevel(tr->root, 'E', 0);
    insert(&tr->root, 'F');
    FindLevel(tr->root, 'F', 0);
    insert(&tr->root, 'G');
    FindLevel(tr->root, 'G', 0);
    insert(&tr->root, 'H');
    FindLevel(tr->root, 'H', 0);
    insert(&tr->root, 'I');
    FindLevel(tr->root, 'I', 0);
    preorder(tr->root);
    printf("\n");
    inorder(tr->root);
    printf("\n");
    postorder(tr->root);
    return 0;
}