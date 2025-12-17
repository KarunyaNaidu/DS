#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void insert_begin()
{
    struct node *newnode;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    struct node *newnode, *temp;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insert_pos()
{
    struct node *newnode, *temp;
    int val, pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &val);
    newnode->data = val;

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while(i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Create\n2.Insert at beginning\n3.Insert at position\n4.Insert at end\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: insert_begin(); break;
            case 3: insert_pos(); break;
            case 4: insert_end(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
