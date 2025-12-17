#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert()
{
    int item;
    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Overflow\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = item;
    printf("Element inserted successfully\n");
}

void delete()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty\n");
        return;
    }

    printf("Circular Queue elements:\n");
    int i = front;
    while (1)
    {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
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
