//queue practing using array
#include <stdio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void show();
int front=-1,rear=-1,queue[20],size,choice;
int data;

void main()
{
    printf("Enter max size of array: ");
    scanf("%d",&size);
    printf("Enter the below choices...");
    printf("\n");
    while(1)
    {
        printf("\t\n1.ENQUEUE\t\n2.DEQUEUE\t\n3.SHOW\t\n4.EXIT");
        printf("\n  Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: show();
                    break;
            case 4: printf("\t\nExited from the queue.");
                    exit(0);
            default:printf("Please enter a valid choice");
        }
    }
}

void enqueue()
{
    if(rear == size-1)
    {
        printf("    Queue overflow");
    }
    else if(rear==-1 && front==-1)
    {
        printf(" Enter data: ");
        scanf("%d",&data);
        front=rear=0;
        queue[rear] = data;
    }
    else
    {
        printf(" Enter data: ");
        scanf("%d",&data);
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("    Queue underflow");
    }
    else if(front == rear)
    {
        front = rear = -1;
        printf("Deleted item from the queue is %d",queue[front]);
    }
    else
    {
        printf("Deleted item from the queue is %d",queue[front]);
        front++;
    }
}

void show()
{
    if(front == -1 && rear == -1)
    {
        printf("    Queue is empty");
    }
    else
    {
        for(int i=front;i<rear+1;i++)
        {
            printf("%d   ",queue[i]);
        }
    }
}
