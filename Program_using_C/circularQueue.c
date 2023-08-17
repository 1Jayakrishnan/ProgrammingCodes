//circular queue using array 
#include <stdio.h>
#include <stdlib.h>
void enq();
void deq();
void show();

int queue[100],item,rear=-1,front=-1;
int choice,n;
void main()
{
    printf("Enter the size of circular queue: ");
    scanf("%d",&n);
    printf("Enter the below choices...");
    while(1)
    {
        printf("\n\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.SHOW\n\t4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enq();
                    break;
            case 2: deq();
                    break;
            case 3: show();
                    break;
            case 4: printf("Exited from the circuler queue");
                    exit(0);
            default:printf("Enter a valid choice");
        }
    }
}

void enq()
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        printf(" Enter item to be insert: ");
        scanf("%d",&item);
        queue[rear] = item;
    }
    else if(((rear+1)%n) == front)
    {
        
        printf(" Queue overflow");
    }
    else
    {
        printf(" Enter item to be insert: ");
        scanf("%d",&item);
        rear = (rear+1)%n;
        queue[rear] = item;
    }
}

void deq()
{
    if(front == -1 && rear == -1)
    {
        printf(" Queue underflow");
    }
    else if(front == rear)
    {
        printf(" Deleted item is %d",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf(" Deleted item is %d",queue[front]);
        front = (front+1)%n;
    }
}

void show()
{
    int i=front;
    if(front == -1 && rear == -1)
    {
        printf("  Queue is empty");
    }
    else
    {
        printf("Circular queue is:\n");
        while(i != rear)
        {
            printf("   %d",queue[i]);
            i=(i+1)%n;
        }
        printf("   %d",queue[rear]);
    }
}
