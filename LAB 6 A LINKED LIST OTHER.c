#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

struct node* create(struct node *head)
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
    return head;
}

void display(struct node *head)
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

void sort(struct node *head)
{
    struct node *i, *j;
    int temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    for(i = head; i->next != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted\n");
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL, *current = head, *next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    printf("List reversed\n");
    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp;
    if(head1 == NULL)
        return head2;

    temp = head1;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Lists concatenated\n");
    return head1;
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Create List 1\n2.Create List 2\n3.Display List 1\n4.Display List 2\n5.Sort List 1\n6.Reverse List 1\n7.Concatenate List 1 & List 2\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: head1 = create(head1); break;
            case 2: head2 = create(head2); break;
            case 3: display(head1); break;
            case 4: display(head2); break;
            case 5: sort(head1); break;
            case 6: head1 = reverse(head1); break;
            case 7: head1 = concatenate(head1, head2); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
