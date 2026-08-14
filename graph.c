#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    char DATA;
    struct node *next;
} NODE;
typedef struct list
{
    NODE *head;
} LIST;
typedef struct graph
{
    int ns;
    LIST *table;
} GRAPH;
NODE *creationNODE(char c)
{
    NODE *new = malloc(sizeof(NODE));
    new->DATA = c;
    new->next = NULL;
    return new;
}
GRAPH *creationGRAPH(int ns)
{
    GRAPH *new = malloc(sizeof(GRAPH));
    new->ns = ns;
    new->table = malloc(ns * sizeof(LIST));
    for (size_t i = 0; i < ns; i++)
    {
        new->table[i].head = NULL;
    }
    return new;
}
void InitializeGRAPH(GRAPH *g)
{

    for (size_t i = 0; i < g->ns; i++)
    {
        char c;
        printf("enter the %d character node : ", i + 1);
        scanf(" %c", &c);
        g->table[i].head = creationNODE(c);
    }
    printf("done\n");
}
bool insert(GRAPH *g, char src, char des)
{
    for (size_t i = 0; i < g->ns; i++)
    {
        if (g->table[i].head->DATA == src)
        {
            NODE *temp = g->table[i].head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = creationNODE(des);
            ;
            printf("finish the new insert\n");
            return true;
        }
    }
    return false;
}
void show(GRAPH *g)
{
    for (size_t i = 0; i < g->ns; i++)
    {
        NODE *temp = g->table[i].head;
        printf("the node %c is connected to ", temp->DATA);
        temp = temp->next;
        while (temp != NULL)
        {
            printf(" %c  ", temp->DATA);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    GRAPH *newg = creationGRAPH(5);
    InitializeGRAPH(newg);
    insert(newg, 'B', 'V');
    insert(newg, 'B', 'C');
    insert(newg, 'V', 'C');
    show(newg);
}