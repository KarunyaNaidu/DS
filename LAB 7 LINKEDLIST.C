#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    int n, val;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &val);

        newnode->data = val;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void insert_left()
{
    struct node *temp, *newnode;
    int key, val;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to insert before: ");
    scanf("%d", &key);

    printf("Enter new data: ");
    scanf("%d", &val);

    temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = temp;
    newnode->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
    printf("Node inserted\n");
}

void delete_value()
{
    struct node *temp;
    int key;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;
    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted\n");
}

void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Create\n2.Insert Left\n3.Delete by Value\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_value(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
