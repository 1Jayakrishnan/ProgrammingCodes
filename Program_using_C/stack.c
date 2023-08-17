//stack practice

#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
int top=-1;
int n,stack[20],choice,value,top;

void main()
{
    printf("Enter the max: ");
    scanf("%d",&n);
    printf("Enter the choice from given below(1/2/3/4): ");
    printf("\n\n");
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

void push()
{
    if(top<n-1)
    {
        printf("Enter the value to be inserted: ");
        scanf("%d",&value);
        top=top+1;
        stack[top]=value;
    }
    else
        printf("\n\tSTACK OVERFLOW\n");
}
void pop()
{
    if(top == -1)
    {
        printf("\tSTACK UNDERFLOW\n");
    }
    else
    {
        value=stack[top];
        printf("Deleted element from the stack is: %d",value);
        top--;
    }
}
void display()
{
    if(top > -1)
    {
        printf("The stack elements are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("\n\t %d",stack[i]);
        }
    }
    else
        printf("  The stack is empty.\n");
}   
