#include <stdio.h>
#include <stdlib.h>

void insertion_at_end();
void insertion_at_begin();
void insert_at_any_position();
void delete_from_begin();
void delete_from_end();
void delete_at_any_position();
void show();

int choice,n,key;

struct node
{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode,*temp1;
void main()
{
    head=NULL;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next=newnode;
            temp = newnode;
        }
    }
    while(1)
    {
        printf("\n\t1.Insertion_at_end\n\t2.Insertion_at_begin\n\t3.Insert_at_any_position\n\t4.Delete_from_begin");
        printf("\n\t5.Delete_from_end\n\t6.Delete_at_any_position\n\t7.Show\n\t8.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insertion_at_end();
                    break;
            case 2: insertion_at_begin();
                    break;
            case 3: insert_at_any_position();
                    break;
            case 4: delete_from_begin();
                    break;
            case 5: delete_from_end();
                    break;
            case 6: delete_at_any_position();
                    break;
            case 7: show();
                    break;
            case 8: exit(0);
        }
    }
}

void insertion_at_end()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newnode;
    printf(" Node inserted at the end");
}


void insertion_at_begin()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data for node: ");
    scanf("%d",&newnode->data);
    printf(" Node inserted at the front");
    newnode->next = head;
    head = newnode;
}

void insert_at_any_position()
{
    printf("Enter a key value for adding a newnode after that key value: ");
    scanf("%d",&key);
    temp = head;
    while(temp->data != key && temp->next != NULL)
    {
        temp = temp->next;
    }
    if(temp->data != key || temp->next == NULL)
    {
        printf("Insertion failed");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node: ");
        scanf("%d",&newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
        printf(" Node inserted at specified location");
    }
}

void delete_from_begin()
{
    if(head == NULL)
    {
        printf("Deletion failed list is empty");
    }
    else
    {
        temp = head;
        head = temp->next;
        printf("  Deleted data is %d",temp->data); 
        free(temp);
    }
}

void delete_from_end()
{
    temp = head;
    while(temp->next != NULL)
    {
        temp1 = temp;
        temp = temp->next;
    }
    printf(" Deleted node is: %d",temp->data);
    if(temp == head)
    {
        head = NULL;
    }
    else
    {
        temp1->next = NULL;
    }
    free(temp);
}

void delete_at_any_position()
{
    temp = head;
    printf("Which node is wanted to delete: ");
    scanf("%d",&key);
    while(temp->data != key)
    {
        temp1 = temp;
        temp = temp->next;
    }
    printf("  Node is deleted");
    if(temp == head)
       head = NULL;
    else
       temp1->next = temp->next;
    free(temp);
}

void show()
{
    temp = head;
    printf("  ");
    if(temp == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        printf("The linked list is\n");
        printf("  ");
        while(temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}
