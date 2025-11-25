#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head=NULL;
node *create(int data)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;

}
void insertAtleft(int data)
{   node *newnode=create(data);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void Deletebyvalue(int value)
{

    if(head==NULL)
    {
        printf("List is empty");
    }
    else{
        node *temp=head;
        while(temp!=NULL&&temp->data!=value)
        {
            temp=temp->next;
        }
        if(temp==NULL)
        {
            printf("\n %d not found",value);
        }
        if(temp==head)
        {
            head=head->next;
            if(head!=NULL)
            {
                head->prev=NULL;
            }
            free(temp);
            return ;
        }
        if(temp->next==NULL)
        {
            temp->prev->next=NULL;
            free(temp);
            return;
        }
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
    }
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
            printf("%d<->",temp->data);
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
        printf("\n 1.Insert at left");
        printf("\n 2.Delete by value");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the value to insert:");
            scanf("%d",&value);
            insertAtleft(value);
            break;
        case 2:
            printf("Enter the value to delete from the list:");
            scanf("%d",&value);
            Deletebyvalue(value);
            break;
        case 3:
            display();
        case 4:
            exit(0);
            break;
        default:
            printf("\n Enter a correct choice");
        }
    }
}
