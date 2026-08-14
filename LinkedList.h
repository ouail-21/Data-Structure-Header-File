#include <stdio.h>
#include <stdlib.h>
typedef struct Node_t
{
    char element;
    struct Node_t *NextNode;
    struct Node_t *PreviousNode;
} Node;
typedef struct LinkedList_t
{
    Node *firstNode;
} LinkedList;
/*the creation process of the Node*/
Node *CreateNode(char Newe)
{
    Node *NewNode = (Node*)(sizeof(Node));
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
/*the insertion process of a single new element in the linked list*/
void InsertElement(LinkedList *list, char Newelement)
{
    if (list == NULL)
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
            Node *LastNode = list->firstNode;
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
    if (List == NULL)
    {
        printf("\ninvalid state! ...\n");
        return;
    }
    else
    {
        printf("\nthe elements are :\n");
        Node *Node = List->firstNode;
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
// Modifing the chosen element in the list
void ModifyElementList(LinkedList *List, char element, char Newelement)
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
            Node *Node = List->firstNode;
            while (Node->element != element && Node->NextNode != NULL)
            {
                Node = Node->NextNode;
            }
            if (Node->element != element)
            {
                printf("\nthis element %c is not in the list\n", element);
            }
            else
            {
                printf("\nModifing the chosen element '%c' with '%c' ...\n", element, Newelement);
                Node->element = Newelement;
            }
        }
        return;
    }
}
// deleting the chosen element in the list
void DeleteElementList(LinkedList *List, char element)
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