// queue using linked list
#include <stdio.h>
#include <stdlib.h>

int i;

struct node          //node to store data
{
    int data;   
    struct node * next;     //used to store address of next node
}  *front, *rear; 
void Enqueue(int ele);
int Dequeue();
int peek();


void main()
{
    int ch,ele;   
    while(1)
    {
        printf("\n[1]ENQUEUE\n[2]DEQUEUE\n[3]PEEK\n[4]DELETE MULTIPLE OF 10\n[5]EXIT PROGRAM");
        printf("\nENTER YOUR CHOICE => ");                 
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: printf("\nEnter element to add : ");   
                    scanf("%d",&ele);    
                    Enqueue(ele);
                    display();
                    break;
            case 2: printf("\nElement %d is  Successfully Dequeued",Dequeue());
                    display();
                    break;
            case 3 :printf("\nThe Front Element is ",peek());
                    break;
            case 4 :delete();
                    display();
                    break;
            case 5:exit(0);
                
            default:printf("\nInvalid Choice ");
        }
    }
}

void Enqueue(int ele);
{
    struct node *newNode;    
      
    newNode = (struct node *) malloc (sizeof(struct node));     //node to store value
    if(newNode == NULL)  
    {  
        printf("\nUnable to Enqueue\n");  
        return;  
    }  
    else  
    {   
        newNode -> data = ele;  
        if(front == NULL)                 //if queue empty newnode is front
        {  
            front = newNode;  
            rear = newNode;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = newNode;        //newnode inserted at end
            rear = newNode;  
            rear->next = NULL;  
        }  
    }  
}

int Dequeue()
{
    int ele;
    struct node* temp;
    if(isEmpty())
        printf("\nEmpty Queue !!");
    else
    {
        ele = front->data;
        temp = front;             //front is removed and next element is considered as front
        front = front->next;
        free(temp);
        return ele;
    }
}

int isEmpty()
{
    if(front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

int peek()
{
    return front->data;
}


void display()
{
    struct node *temp;  
    temp = front;      
    if(isEmpty())  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nQueue Elements :- ");  
        while(temp != NULL)   
        {  
            printf("%d     ",temp -> data);  
            temp = temp -> next;  
        }  
    }  
}

void delete()
{
    struct node *temp1;
    struct node *temp2;
    temp1 = front;
    temp2 = temp1->next;

    if(temp1->data % 10 == 0)
    {
        front = temp2;
        free(temp1);
    }
    else
    {
        while(temp2 != NULL)
        {
            if(temp2->data % 10 == 0)
                temp1->next = temp2->next;
        
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
}
