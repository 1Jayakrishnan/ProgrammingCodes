//simple linked list 

#include <stdio.h>
#include <stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node * next;
    };
    struct node *head,*newnode,*temp;
    head=NULL;
    int choice=1;
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue(0/1)? ");
        scanf("%d",&choice);
    }
    printf("The linked list is:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
