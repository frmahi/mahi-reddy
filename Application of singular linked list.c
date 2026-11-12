#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
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
    newnode->next=NULL;
    return newnode;
}

int insertend(struct node **head,int data)
{
    struct node *newnode = createnode(data);

    if (newnode == NULL)
    {
        return 0;
    }
    if (*head == NULL)
    {
        *head=newnode;
        return 1;
    }
    struct node *temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return 1;
}

void display(struct node *head)
{
    struct node *temp=head;
    printf("sinngular linked list:");

    while (temp!=NULL)
    {
        printf("%d->",temp->data);
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

int main()
{
    struct node *head=NULL;
    int n,i,data;

    printf("enter number of nodes:");
    if (scanf("%d",&n)!=1 || n<0)
    {
        printf("invalid number of nodes");
        return 1;
    }

    for (i=0;i<n;i++)
    {
        printf("enter data for node %d: ",i+1);
        if (scanf("%d",&data)!=1)
        {
            printf("invalid data input\n");
            freelist(head);
            return 1;
        }
        if (!insertend(&head,data))
        {
            printf("unable to insert data");
            freelist(head);
            return 1;
        }
    }
    display(head);
    freelist(head);
    return 0;
}