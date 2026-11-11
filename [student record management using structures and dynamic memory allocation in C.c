#include <stdio.h>
#include <stdlib.h>

struct student
{
    int roll;
    char name[30];
    float marks;
};

void displayAll(struct student *ptr, int n)
{
    int i;

    printf("\nroll\tname\t\tmarks\n");
    printf("----------------------------\n");

    for (i =0; i < n;i++)
    {
        printf("%d\t%-15s%.2f\n",
        (ptr +i)->roll,
        (ptr +i)->name,
        (ptr +i)->marks);
    }
}

int main()
{
    int n ,i;
    struct student * students;

    printf("enter number of students:");

    if (scanf("%d",&n)!=1 || n<=0)
    {
        printf("invalid number of students");
        return 1;
    }

    students = malloc(n *sizeof(struct student));

    if (students == NULL)
    {
        printf("memory allocation failed");
        return 1;
    }

    for (i =0;i<n;i++)
    {
        printf("enter roll:");
        if (scanf("%d",&(students +i)->roll)!=1)
            goto input_error;
        
        printf("enter name:");
        if (scanf("%29s",(students +i)->name)!=1)
            goto input_error;
        
        printf("enter marks:");
        if (scanf("%f",&(students +i)->marks)!=1)
            goto input_error;
    }

    displayAll(students,n);
    free(students);
    return 0;

    input_error:
        printf("invalid input\n");
        free(students);
        return 1;
        
}