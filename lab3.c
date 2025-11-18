#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define maxsize 2
int a[maxsize];
int front=-1;
int rear=-1;
int x;
int isfull();
int isempty();
void Enqueue();
void Dequeue();
void Display();
void Enqueue()
{
    if(isfull())
    {
        printf("Queue is full\n ");
        return 0;
    }
    printf("Enter the element to insert:");
    scanf("%d",&x);
    if(isempty())
    {
        front=rear=0;
    }
    else{
        rear++;
    }
    a[rear]=x;
    printf("Inserted element is:%d",x);
}
void Dequeue()
{

    if(isempty())
        printf("The queue is empty");
    else if(front==rear)
        front=rear=-1;
    else
    {
        front++;
    }


}
void Display()
{
    printf("The elements in the queue are:");
    for(int i=front;i<rear;i++)
    {
        printf("%d",a[i]);
        printf("\n");
    }
}
int isfull()
{
    if(rear==maxsize-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(front==-1&&rear==-1)
        return 1;
    else
        return 0;
}
void main()
{
    int choice;
    while(1)
    {
        printf("\n ***MENU***");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");
        printf("\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
              {
              case 1:
                Enqueue();
                break;
              case 2:
                Dequeue();
                break;
              case 3:
                Display();
                break;
              case 4:
                exit(0);
                break;
              default:
                printf("Enter a valid choice");
              }

    }
}
