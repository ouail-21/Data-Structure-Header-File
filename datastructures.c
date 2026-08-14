#include <stdio.h>
#include <stdlib.h>
typedef struct Node_t
{
    char* element;
    struct Node_t *NextNode;
    struct Node_t *PreviousNode;
} Node;
typedef struct LinkedList_t
{
    Node *firstNode;
} LinkedList;
typedef struct Stack{
    Node *TopNode;
}Stack;
typedef struct Queue
{
    Node *Head,*tail;
}Queue;
/*the creation process of the Node*/
Node *CreateNode(char* Newe)
{
    Node *NewNode = malloc(sizeof(Node));
    NewNode->element = Newe;
    NewNode->NextNode = NULL;
    NewNode->PreviousNode = NULL;
    return NewNode;
}
/*the creation process of the linked list*/
LinkedList *CreateLikedList()
{
    LinkedList *L = (LinkedList *)malloc(sizeof(LinkedList));
    L->firstNode = NULL;
    return L;
}
/*the creation process of the Stack*/
Stack *createStack(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->TopNode = NULL;
    return S;
}
/*the creation process of the Queue*/
Queue* CreateQueue()
{
    Queue* New = malloc(sizeof(Queue));
    New->Head = New->tail = NULL;
    return New;
}
/*the insertion process of a single new element in the linked list*/
void InsertElement(LinkedList *list, char* Newelement)
{
    if(list == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        Node *NewNode = CreateNode(Newelement);
        /*if the list was empty*/
        if (list->firstNode == NULL)
        {
            printf("\ninserting the New element in the head: %c\n", Newelement);
            list->firstNode = NewNode;
        }
        /*if the list was not empty*/
        else
        {
            printf("\ninserting the New element in the tail: %c\n", Newelement);
            Node* LastNode = list->firstNode;
            /*searching for the last element in the list*/
            while (LastNode->NextNode != NULL)
            {
                LastNode = LastNode->NextNode;
            }
            LastNode->NextNode = NewNode;
            NewNode->PreviousNode = LastNode;
        }
        return;
    }    
}
/*the printing process of the elementd that exist in the list*/
void showList(LinkedList *List)
{
    if(List == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        printf("\nthe elements are :\n");
        Node* Node = List->firstNode;
        if (Node == NULL)
        {
            printf("nothing\n");
        }
        else
        {
            while (Node != NULL)
            {
                printf("%c\t", Node->element);
                Node = Node->NextNode;
            }
        }
        return;
    }    
}
/*the shecking process*/
void IsListEmpty(LinkedList *List)
{
    if (List == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        if (List->firstNode == NULL)
        {
            printf("\nthe list is empty\n");
        }
        else
        {
            printf("\nthe list is not empty\n");
        }
        return;
    }
}
//Modifing the chosen element in the list
void ModifyElementList(LinkedList* List,char* element,char* Newelement)
{
    if (List == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        if (List->firstNode == NULL )
        {
            printf("\nthere is no element in the list\n");
        }
        else{
            Node* Node = List->firstNode;
            while (Node->element != element && Node->NextNode != NULL)
            {
                Node = Node->NextNode;
            }
            if (Node->element != element)
            {
                printf("\nthis element %c is not in the list\n",element);
            }
            else{
            printf("\nModifing the chosen element '%c' with '%c' ...\n",element,Newelement);
            Node->element = Newelement;
            }
        }
        return;
    }
}
//deleting the chosen element in the list
void DeleteElementList(LinkedList* List,char* element)
{
    if (List == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        if (List->firstNode == NULL)
        {
            printf("\nthere is no element in the list\n");
        }
        else
        {
            Node *CurrentNode = List->firstNode;
            if (CurrentNode->element == element)
            {
                printf("\nDeleting the chosen element '%c' ...\n", element);
                List->firstNode = CurrentNode->NextNode;
                free(CurrentNode);
            }
            else
            {
                while (CurrentNode->element != element && CurrentNode->NextNode != NULL)
                {
                    CurrentNode = CurrentNode->NextNode;
                }
                if (CurrentNode->NextNode != NULL && CurrentNode->element == element)
                {
                    printf("\nDeleting the chosen element '%c' in the middle...\n", element);
                    CurrentNode->PreviousNode->NextNode = CurrentNode->NextNode;
                    CurrentNode->NextNode->PreviousNode = CurrentNode->PreviousNode;
                    free(CurrentNode);
                }
                else
                {
                    if (CurrentNode->element == element && CurrentNode->NextNode == NULL)
                    {
                        CurrentNode->PreviousNode->NextNode = NULL;
                        printf("\nDeleting the chosen element '%c' in the tail...\n", element);
                        free(CurrentNode);
                    }
                    else
                    {
                        printf("\nthis element is not in the list\n");
                    }
                }
            }
        }
        return;
    }
}
/*the destroying process of the linked list*/
void DestroyList(LinkedList **List)
{
    if (List == NULL || *List == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        Node *Current = (*List)->firstNode;
        Node *Next = NULL;
        while (Current != NULL)
        {
            Next = Current->NextNode;
            free(Current);
            Current = Next;
        }
        free(*List); 
        *List = NULL;
        printf("\ndestruction process is complete\n");
        return;
    }
}
/*adding a new element on the top of the stack*/
void Push(Stack* S,char* element)
{
    if (S == NULL)
    {
        printf("\ninvalid state ...\n");
        return;
    }
    else
    {
        Node *New = CreateNode(element);
        if(S->TopNode == NULL)
        {
            printf("pushing the new element %c in the basis...\n",element);
            S->TopNode = New;
        }
        else
        {
            printf("pushing the new element %c in the Top...\n",element);
            New->PreviousNode = S->TopNode;
            S->TopNode = New;
        }
        return;
    }
}
/*showing operation of the elements in the stack*/
void showStack(Stack* S)
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
            Node* Current = S->TopNode;
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
char* Pop(Stack* S)
{
    if (S == NULL)
    {
        printf("\ninvalid state ...\n");
        return 0;
    }
    else
    {
        Node* current = S->TopNode;
        if (current == NULL)
        {
            printf("\nthe stack is empty\n");
            return 0;
        }
        else
        {
            printf("\npoping the top element form the stack\n");
            char* c = S->TopNode->element;
            S->TopNode = S->TopNode->PreviousNode;
            free(current);
            return c;
        }
            
    }
}
void IsStackEmpty(Stack* S)
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
        Node *Current = (*S)->TopNode ;
        Node *Next = NULL ;
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
void EQueue(Queue* Q, char* Newelement)
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
            Node *Pre = Q->tail ;
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
void ShowQueue(Queue* Q)
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
void DQueue(Queue* Q)
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
            printf("\nRemoving the element %c from the head of the Queue...\n",Q->Head->element);
            Node* OLd = Q->Head;
            Q->Head = Q->Head->NextNode;
            free(OLd);
            printf("\nDone\n");
            return;
        }
    }
}
void DestroyQueue(Queue** Q)
{
    if (Q == NULL|| *Q == NULL)
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
            Node* Current = (*Q)->Head;
            Node* Next = NULL;
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
int main(void)
{
    Queue *Q = CreateQueue();
  
    return 0;
}