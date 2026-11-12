#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node *head=NULL,*temp,*newnode;
    int n,i,val;

    printf("enter numebr of nodes:");
    scanf("%d",&n);

    for (i=0;i<n;i++)
    {
        printf("enter data for node:");
        scanf("%d",&val);

        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=val;

        if (head==NULL)
        {
            newnode->next=newnode;
            head=newnode;
        }else{
            temp=head;
            while (temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
        }
    }
    printf("circular linked list:");
    temp=head;
    do 
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }while (temp!=head);
    printf("(head)\n");
    return 0;
}