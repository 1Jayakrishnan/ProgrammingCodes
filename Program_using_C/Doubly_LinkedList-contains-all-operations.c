//doubly linked list

#include <stdio.h>
#include <stdlib.h>
void print();
void insert_at_begin();
void delete_from_end();
void insert_at_intermediate();
void insert_at_end();
void create_new_list();
void delete_from_begin();
void delete_intermediate_position();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *newnode,*temp,*temp1,*temp2;
int choice,n;
void main()
{
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        print();
    }
    while(1)
    {
        printf("\n\t1.Insert at begin\n\t2.Delete from end\n\t3.Insert at intermediate\n\t4.Insert at end\n");
        printf("\t5.Create new linked list(if list is empty)\n\t6.Delete from begin\n\t7.Delete intermediate position\n\t8.Print linked list\n");
        printf("\t9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_at_begin();
                    break;
            case 2: delete_from_end();
                    break;
            case 3: insert_at_intermediate();
                    break;
            case 4: insert_at_end();
                    break;
            case 5: create_new_list();
                    break;
            case 6: delete_from_begin();
                    break;
            case 7: delete_intermediate_position();
                    break;
            case 8: print();
                    break;
            case 9: printf("Exited from the list.....");
                    exit(0);
            default:printf("Enter a valid choice from the above list");
        }
    }
}
//Inserting a new node to the beginning of the linked list
void insert_at_begin()
{
    temp = head;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        temp->prev = newnode;
        newnode->next = temp;
        newnode->prev = NULL;
        head = temp = newnode;
        printf("  Node inserted at the begin");
    }
}
//Deleting last node from the linked list
void delete_from_end()
{
    temp = head;
    if(head == NULL)
    {
        printf("List is empty cannot insert");
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Deleted node is: %d",temp->data);
        if(temp->prev == NULL)
        {
            head = NULL;
        }
        else
        {
            temp1 = temp->prev;
            temp1->next = NULL;
            free(temp);
        }
    }
}
//Inserting a new node in the intermediate of the linked list
void insert_at_intermediate()
{
    int key;
    temp = head;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Enter key node for adding newnode after that key node: ");
        scanf("%d",&key);
        while(temp->data != key && temp->next != NULL)
        {
            temp = temp->next;
        }
        if(temp->data == key && temp->next != NULL)
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d",&newnode->data);
            temp1 =  temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = temp1;
            temp1->prev = newnode;
            temp = newnode;
            printf("  Node inserted to the list");
        }
        else
        {
            printf("Insertion failed");
        }
        
    }
}
//Inserting a new node to the end of the linked list 
void insert_at_end()
{
    if(head == NULL)
    {
        printf("List is empty cannot insert");
    }
    else
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
        temp = newnode;
        printf("  Node is inserted at the end");
    }
}
//Creating a new linked list
void create_new_list()
{
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ",i);
        scanf("%d",&newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        print();
    }
}
//Deleting node from the beginning of the linked list
void delete_from_begin()
{
    temp = head;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp1 = head;
        int count = 0,n;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
            count++;
        }
        n = count+1;
        if(n == 1)
        {
            printf("Deleted node from the list is: %d",temp->data);
            head = NULL;
        }
        else
        {
            printf("Deleted node from the list is: %d",temp->data);
            temp1 = temp->next;
            temp1->prev = NULL;
            head = temp1;
            free(temp);
        }
    }
}
//Deleting any intermediate node from the list
void delete_intermediate_position()
{
    temp = head;
    int key;
    if(head == NULL)
    {
        printf("Deletion failed");
    }
    else
    {
        printf("Enter which intermediate node to be delete: ");
        scanf("%d",&key);
        while(temp->data != key)
        {
            temp = temp->next;
        }
        if(temp->prev != NULL && temp->next != NULL)
        {
            temp1 = temp->prev;
            temp2 = temp->next;
            temp1->next = temp2;
            temp2->prev = temp1;
            printf("Deleted node from the list is %d",temp->data);
            free(temp);
        }
        else
        {
            printf("Deletion failed");
        }
    }
}
//Printing the linked list
void print()
{
    temp = head;
    if(temp == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        printf("The linked list is....\n   ");
        while(temp->next != NULL)
        {
            printf("%d   ",temp->data);
            temp = temp->next;
        }
        printf("%d   ",temp->data);
    }
}
