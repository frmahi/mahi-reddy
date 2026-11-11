#include <stdio.h>
#define MAX 5

int stack[MAX],top =-1;
void push(int val)
{
    if (top == MAX -1)
    {
        printf("stack overflow\n");
    }
    else
    {
        stack[++top]=val;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("deleted element:%d\n",stack[top--]);
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("stack(top to bottom):");

    for (i =top;i>=0;i--)
    {
        printf("%d",stack[i]);
    printf("\n");
    }
}
int main()
{
    int n,i,val;

    printf("enter number of elements to push(max %d):",MAX);

    if (scanf("%d",&n)!=1 || n<=1 || n > MAX)
    {
        printf("invalid number of students");
        return 1;
    }
    for ( i =0; i<n;i++)
    {
        printf("enter element%d:",i+1);

        if (scanf("%d",&val)!=1)
        {
            printf("invalid input\n");
            return 1;
        }
        push(val);

    }
    printf("\nbefore pop:\n");
    display();

    pop();
    printf("\nafter pop:\n");
    display();
}