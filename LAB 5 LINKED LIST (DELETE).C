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

void delete_first()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted\n");
}

void delete_last()
{
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

void delete_specified()
{
    struct node *temp, *prev;
    int key;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    if(head->data == key)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    temp = head;
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
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
        printf("\n1.Create\n2.Delete First\n3.Delete Specified\n4.Delete Last\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: delete_first(); break;
            case 3: delete_specified(); break;
            case 4: delete_last(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
