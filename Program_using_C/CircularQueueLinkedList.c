//circular queue using linked list practice

#include <stdio.h>
#include <stdlib.h>
void enq();
void deq();
void show();

int choice,item;
struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear =0;
void main()
{
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
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf(" Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(rear == 0)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void deq()
{
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0)
    {
        printf("Circular queue underflow");
    }
    else if(front == rear)
    {
        printf("Deleted item from the list is: %d",temp->data);
        front = rear = 0;
        free(temp);
    }
    else
    {
        printf("Deleted item from the list is: %d",temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void show()
{
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0)
    {
        printf(" Circular queue is empty");
    }
    else
    {
        while(temp->next != front)
        {
            printf("%d   ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
}
