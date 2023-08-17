//stack linked list practice
#include <stdio.h>
#include <stdlib.h>
void push();
void display();
void pop();
void main()
{
    int choice;
    printf("Enter the choice from given below(1/2/3/4): ");
    printf("\n");
    do
    {   
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exited from the stack");
                    exit(0);            
        }
    }while(choice != 4);
}
struct node
{
    int data;
    struct node * link;
};
struct node *top=0;
//push elements @ the beginning of the linked list
void push()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be pushed into the stack: ");
    scanf("%d",&newnode->data);
    newnode->link=top;
    top=newnode;
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("\tStack is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("  %d\n",temp->data);
            temp=temp->link;
        }
    }
}
//pop elements @ the beginning from the linked list
void pop()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
    {
        printf("\tStack underflow");
    }
    else
    {
        printf("popped data is %d\n",top->data);
        top=top->link;
        free(temp);
    }
}
