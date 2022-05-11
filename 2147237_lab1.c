//Linked List

#include <stdio.h>
#include <stdlib.h>

void push(int ele);
int pop();
int peek();
int isEmpty();
void display();
void reverse();

int i;

struct node
{
    int data;
    struct node * next;
} *top, *head; 

void main()
{
    int ch,ele;   
    while(1)
    {
        printf("\n[1] PUSH\n[2] POP\n[3] PEEK\n[4] EXIT PROGRAM\n");
        printf("\nENTER YOUR CHOICE => ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\nENTER TO ADD ELEMENT : ");
                    scanf("%d",&ele);
                    push(ele);
                    display();
                    break;
            case 2: printf("\nELEMENT %d POPED SUCCESSFULLY",pop());
                    display();
                    break;
            case 3 :printf("\nTOP MOST ELEMENT IS %d",peek());
                    break;
            case 4 ://reverse();
                    break; 
            case 5: exit(0);
                
            default:printf("\nINVALID CHOICE TRY AGAIN!! ");
        }
    }
}

void push(int ele)
{
   
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL)
        printf("\n\nUNABLE TO PUSH TRY AGAIN!!!!");
    else
    {
        if(top == NULL)
        {
            temp->data = ele;
            temp->next = NULL;
            head = temp;

        }
        else
        {
            temp->data = ele;
            temp->next = top;
        }
        top = temp;
    }
    printf("\nELEMENT PUSHED SUCCESSFULLY!!");
}

int pop()
{
    int ele;
    struct node *temp; 
    if(isEmpty())
        printf("\nSTACK UNDERFLOW!!");
    else
    {
        ele = top->data;
        temp = top;
        top = top->next;
        free(temp);
        return ele;
    }
}

int peek()
{
    if(isEmpty())
        return 0;
    else
        return top->data; 
}

int isEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

void display()
{
    struct node *temp;
    temp = top;
    if(isEmpty())
        printf("\n\nEMPTY STACK :(");

    else
    {
        printf("\n\nSTACK ELEMENT :-  ");
        while(temp != NULL)
        {
            printf("%d   ",temp->data);
            temp = temp->next;
        }
    }
}

void reverse()
{
   struct node *temp;
   for(temp=head;temp !=NULL;temp=temp->next)
   {
       push(temp->data);
       temp->data = pop();
   }
}



