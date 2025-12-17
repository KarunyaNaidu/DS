#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push()
{
    struct node *newnode;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("Element pushed\n");
}

void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display_stack()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Stack elements:\n");
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void enqueue()
{
    struct node *newnode;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Element inserted\n");
}

void dequeue()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;
    free(temp);
}

void display_queue()
{
    struct node *temp;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("Queue elements:\n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push(Stack)\n2.Pop(Stack)\n3.Display Stack\n4.Enqueue(Queue)\n5.Dequeue(Queue)\n6.Display Queue\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display_stack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: display_queue(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
