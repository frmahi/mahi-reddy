#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0,rear =-1;

void enqueue(int val)
{
    if (rear == MAX -1)
    {
        printf("queue overflow\n");
    }else{
        rear++;
        queue[rear]= val;
    }
}
void dequeue()
{
    if (front > rear)
    {
        printf("queue underflow\n");
    }else{
        printf("deleted element:%d\n ",queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front > rear)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue:");

    for (i =front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    printf("\n");
    }
}

int main()
{
    int n,i,val;

    printf("enter mumber of  elements:");
    scanf("%d",&n);
    if (n < 1 || n > MAX)
    {
        printf("invalid number of elements");
        return 1;
    }
    for ( i =0 ; i <n;i++)
    {
        printf("enter element %d:",i+1);
        scanf("%d",&val);

        enqueue(val);
    }
    printf("\nbefore dequeue\n");
    display();

    dequeue();

    printf("\nafter dequeue\n");
    display();
}