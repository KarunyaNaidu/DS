#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;
node *create(int data)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode
}
void Pushstack(int data)
{

    node *newnode=create(data);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void Popstack()
{

    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        node *temp=head;
        head=head->next;
        free(temp);
    }
}
void Enqueue(int data)
{   node *newnode=create(data);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void Dequeue()
{
    Popstack();
}
void display()
{
    if(head==NULL)
    {

        printf("List is empty");
    }
    else
    {
        node *temp=head;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}
void main()
{
    int ch,value;
    while(1)
    {
        printf("\n ***MENU***");
        printf("\n 1.Push into the stack");
        printf("\n 2.Pop from the stack");
        printf("\n 3.Enqueue into queue");
        printf("\n 4.Dequeue from queue");
        printf("\n 5.Display");
        printf("\n 6.Exit");
        printf("\n Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the value to  push into the stack:");
            scanf("%d",&value);
            Pushstack(value);
            break;
        case 2:
            Popstack();
            break;
        case 3:
            printf("Enter the value to insert into the Queue:");
            scanf("%d",&value);
            Enqueue(value);
            break;
        case 4:
            Dequeue();
            break;
        case 5:
            display();
        case 6:
            exit(0);
            break;
        default:
            printf("\n Enter a correct choice");
        }
    }
}
