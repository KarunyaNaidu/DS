#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void insert()
{
    int item;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &item);
    queue[++rear] = item;
    printf("Element inserted successfully\n");
}

void delete()
{
    if (front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front++]);
}

void display()
{
    if (front > rear)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
