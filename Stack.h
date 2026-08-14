#include <stdio.h>
#include <stdlib.h>
typedef struct Node_t
{
    char element;
    struct Node_t *NextNode;
    struct Node_t *PreviousNode;
} Node;
typedef struct Stack
{
    Node *TopNode;
} Stack;
/*the creation process of the Node*/
Node *CreateNode(char Newe)
{
    Node *NewNode = (Node*)(sizeof(Node));
    NewNode->element = Newe;
    NewNode->NextNode = NULL;
    NewNode->PreviousNode = NULL;
    return NewNode;
}
/*the creation process of the Stack*/
Stack *createStack()
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->TopNode = NULL;
    return S;
}
/*adding a new element on the top of the stack*/
void Push(Stack *S, char element)
{
    if (S == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        Node *New = CreateNode(element);
        if (S->TopNode == NULL)
        {
            printf("pushing the new element %c in the basis...\n", element);
            S->TopNode = New;
        }
        else
        {
            printf("pushing the new element %c in the Top...\n", element);
            New->PreviousNode = S->TopNode;
            S->TopNode = New;
        }
        return;
    }
}
/*showing operation of the elements in the stack*/
void showStack(Stack *S)
{
    if (S == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        printf("the elements of the stack are :");
        if (S->TopNode == NULL)
        {
            printf("\nNothing...\n");
        }
        else
        {
            Node *Current = S->TopNode;
            while (Current != NULL)
            {
                printf("\n%c\t", Current->element);
                Current = Current->PreviousNode;
            }
        }
        return;
    }
}
/*the poping process of the top element from the Stack*/
char Pop(Stack *S)
{
    if (S == NULL)
    {
        printf("\ninvalid state ...\n");
        return 1;
    }
    else
    {
        Node *current = S->TopNode;
        if (current == NULL)
        {
            printf("\nthe stack is empty\n");
            return 1;
        }
        else
        {
            printf("\npoping the top element form the stack\n");
            char c = S->TopNode->element;
            S->TopNode = S->TopNode->PreviousNode;
            free(current);
            return c;
        }
    }
}
void IsStackEmpty(Stack *S)
{
    if (S == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        if (S->TopNode == NULL)
        {
            printf("the stack is empty\n");
            return;
        }
        else
        {
            printf("the stack is not empty\n");
            return;
        }
    }
}
void destroyStack(Stack **S)
{
    if (S == NULL || *S == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        Node *Current = (*S)->TopNode;
        Node *Next = NULL;
        while (Current != NULL)
        {
            Next = Current->PreviousNode;
            free(Current);
            Current = Next;
        }
        free(*S);
        *S = NULL;
        printf("\ndestruction process is complete\n");
    }
}