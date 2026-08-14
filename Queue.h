#include <stdio.h>
#include <stdlib.h>
typedef struct Node_t
{
    char element;
    struct Node_t *NextNode;
    struct Node_t *PreviousNode;
} Node;
typedef struct Queue
{
    Node *Head, *tail;
} Queue;
/*the creation process of the Node*/
Node *CreateNode(char Newe)
{
    Node *NewNode = (Node*)(sizeof(Node));
    NewNode->element = Newe;
    NewNode->NextNode = NULL;
    NewNode->PreviousNode = NULL;
    return NewNode;
}
/*the creation process of the Queue*/
Queue *CreateQueue()
{
    Queue *New = (Queue*)(sizeof(Queue));
    New->Head = New->tail = NULL;
    return New;
}
void EQueue(Queue *Q, char Newelement)
{
    if (Q == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        Node *New = CreateNode(Newelement);
        if (Q->Head == NULL)
        {
            printf("\nInsertin a New element %c in the empty Queue ...\n", Newelement);
            Q->Head = Q->tail = New;
            printf("Done !\n");
            return;
        }
        else
        {
            printf("\nInserting a New element %c in the tail...\n", Newelement);
            Node *Pre = Q->tail;
            Q->tail->NextNode = New;
            Q->tail = New;
            New->PreviousNode = Pre;
            printf("Done !\n");
            return;
        }
    }
}
int IsQueueEmpty(Queue *Q)
{
    if (Q == NULL)
    {
        printf("\ninvalid state ...\n");
        return 1;
    }
    else
    {
        if (Q->Head == NULL && Q->tail == NULL)
        {
            printf("\nYes the Queue is Empty\n");
            return 0;
        }
        else
        {
            printf("\nNo the Queue is Not Empty\n");
            return 0;
        }
    }
}
void ShowQueue(Queue *Q)
{
    if (Q == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        if (Q->Head == NULL)
        {
            printf("\nthe Queue is Empty\n");
            return;
        }
        else
        {
            printf("\nthe elements of the Queue are: \n");
            Node *Current = Q->Head;
            while (Current != NULL)
            {
                printf("%c\t", Current->element);
                Current = Current->NextNode;
            }
            return;
        }
    }
}
void DQueue(Queue *Q)
{
    if (Q == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        if (Q->Head == NULL)
        {
            printf("\nthe Queue is Empty\n");
            return;
        }
        else
        {
            printf("\nRemoving the element %c from the head of the Queue...\n", Q->Head->element);
            Node *OLd = Q->Head;
            Q->Head = Q->Head->NextNode;
            free(OLd);
            printf("\nDone\n");
            return;
        }
    }
}
void DestroyQueue(Queue **Q)
{
    if (Q == NULL || *Q == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        if ((*Q)->Head == NULL)
        {
            printf("\nDestroying an empty Queue...\n");
            free(*Q);
            free(Q);
            Q = NULL;
            printf("Done\n");
            return;
        }
        else
        {
            printf("\nDestroying a non empty Queue\n");
            Node *Current = (*Q)->Head;
            Node *Next = NULL;
            while (Current != NULL)
            {
                Next = Current->NextNode;
                free(Current);
                Current = Next;
            }
            free(*Q);
            *Q = NULL;
            printf("\nDone\n");
            return;
        }
    }
}