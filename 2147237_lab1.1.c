//stack
#include <stdio.h>
#include <stdlib.h>

void push(int *arr,int n,int ele);
int pop(int *arr,int n);
void peek(int *arr,int n);
int isEmpty();
void display(int *arr);
void insertAtBottom(int *arr,int n,int ele);
void reverse(int *arr,int n);

static int top;

void main()
{
    int ch,n,ele;
    int *arr;
    printf("ENTER SIZE OF AN ARRAY :- ");                  //size of array
    scanf("%d",&n);

    arr = (int *)malloc(n*sizeof(int));                     //memory allocation of array

    while(1)
    {
        printf("\n[1] PUSH\n[2] POP\n[3] PEEK\n[4] EXIT PROGRAM\n");
        printf("\nENTER YOUR CHOICE => ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\nENTER TO ADD ELEMENT : ");
                    scanf("%d",&ele);                               //take input
                    push(arr,n,ele);                                //push the element
                    display(arr);
                    break;
            case 2: printf("\nELEMENT %d POPED SUCCESSFULLY",pop(arr,n));       //display poped element
                    display(arr);   
                    break;
            case 3 :peek(arr,n);                //return topmost element
                    
                    break;
            case 4 :reverse(arr,n);             //reverse the stack
                    display(arr);
                    break;
            case 5: exit(0);
                
            default:printf("\nINVALID CHOICE TRY AGAIN!! ");
        }
    }
}

void push(int *arr,int n,int ele)
{
    

    if(top>=n-1)

        printf("\nSTACK OVERFLOW!! ");
    else
    {
        
        top ++;
        arr[top] = ele;
    }
}

int pop(int *arr,int n)
{
    if(isEmpty())
    {
        printf("\nSTACK UNDERFLOW!!");
        return 0;
    }
    else
    {
        top--;
        return arr[top+1];   
        
    }
}

void peek(int *arr,int n)
{
    if(isEmpty())
        printf("\n\nEMPTY STACK :(");
    else
        printf("\nTOP MOST ELEMENT IS : %d",arr[top]);
}

int isEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

void display(int *arr)
{
    int i;
    if(top>=0)
    {
        printf("\nSTACK :-  ");
        for(i=top; i>0; i--)
            printf("%d    ",arr[i]);
    }
    else
    {
        printf("\nSTACK IS EMPTY!!");
    }
}

void insertAtBottom(int *arr,int n,int ele) 
{
    if (isEmpty())
        push(arr,n,ele);
    else 
    {
      int top = pop(arr,n);
      insertAtBottom(arr,n,ele);
      push(arr,n,top);
    }
}
 
void reverse(int *arr,int n)
 {
    if (!isEmpty())
     {   
        int top = pop(arr,n);
        reverse(arr,n);
        insertAtBottom(arr,n,top);
    }
    else
        return;
}
