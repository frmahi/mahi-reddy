#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode=malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("memory allocation failed");
        return NULL;
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
int insertend(struct node **head,struct node **tail,int data)
{
    struct node *newnode =createnode(data);

    if (newnode==NULL)
    {
        return 0;
    }
    if (*head==NULL)
    {
        *head=newnode;
        *tail=newnode;
    }else{
        newnode->prev=*tail;
        (*tail)->next=newnode;
        *tail=newnode;

    }
    return 1;
}
void displayforward(struct node *head)
{
    struct node *temp=head;
    printf("forward:");
    while (temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void displaybackward(struct node *tail)
{
    struct node *temp=tail;
    printf("backward:");
    while (temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void freelist(struct node *head)
{
    struct node *temp;
    while (head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main(void)
{
    struct node *head=NULL;
    struct node *tail=NULL;
    int n,i,data;

    printf("enter number of nodes:");
    if (scanf("%d",&n)!=1 || n<0)
    {
        printf("invalid number of nodes");
        return 1;
    }
    for (i=0;i<n;i++)
    {
        printf("enter data for nodes %d: ",i+1);
        if (scanf("%d",&data)!=1)
        {
            printf("invalid input data\n");
            freelist(head);
            return 1;
        }
        if (!insertend(&head,&tail,data))
        {
            printf("unable to insert data");
            freelist(head);
            return 1;
        }
    }
    displayforward(head);
    displaybackward(head);
    freelist(head);
    return 0;
}