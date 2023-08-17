//queue using linked list practice

#include <stdio.h>
#include <stdlib.h>
void enq();
void deq();
void show();

struct node
{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;

void main()
{
    int size,choice;
    //printf("Enter max size of array: ");
    //scanf("%d",&size);
    printf("Enter the below choices...");
    printf("\n");
    while(1)
    {
        printf("\t\n1.ENQUEUE\t\n2.DEQUEUE\t\n3.SHOW\t\n4.EXIT");
        printf("\n  Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enq();
                    break;
            case 2: deq();
                    break;
            case 3: show();
                    break;
            case 4: printf("\t\nExited from the queue.");
                    exit(0);
            default:printf("Please enter a valid choice");
        }
    }
}

void enq()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void deq()
{
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0)
    {
        printf("Queue underflow");
    }
    else
    {
        printf("Deleted item from the queue is %d",front->data);
        front = front->next;
        free(temp);
    }
}

void show()
{
    struct node *temp;
    if(front == 0 && rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        temp=rear;
        while(temp != 0)
        {
            printf(" %d    ",temp->data);
            temp=temp->next; 
        }
    }
}
