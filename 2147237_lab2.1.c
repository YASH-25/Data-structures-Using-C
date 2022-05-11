//queue

#include <stdio.h>
#include <stdlib.h>

static int n;
int front = 0;
int rear = 0;

void main()
{
    int ch,ele;
    int *arr;

    printf("ENTER SIZE OF AN ARRAY :- ");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));   
    
    while(1)
    {
        printf("\n[1]ENQUEUE\n[2]DEQUEUE\n[3]PEEK\n[4]EXIT PROGRAM");
        printf("\nENTER YOUR CHOICE => ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: printf("\nENTER TO ADD : ");
                    scanf("%d",&ele);    
                    Enqueue(arr,ele);
                    display(arr);
                    break;
            case 2: printf("\nELEMENT %d IS DEQUEUED",Dequeue(arr));
                    display(arr);
                    break;
            case 3 :printf("\nTHE FRONT ELEMENT IS ",peek(arr));
                    break;
           case 4 : exit(0);
                
            default:printf("\nINVALID CHOICE TRY AGAIN!! ");
        }
    }
}

void Enqueue(int *arr,int ele)
{
    if(isEmpty())
    {
        arr[front] = arr[rear] = ele;
        rear++;
    }   
    else
    {
        arr[rear] = ele;
        rear++;
    }
}

int Dequeue(int *arr)
{
    int i,temp;
    if(isEmpty())
    {
        printf("\nQUEUE IS EMPTY!!\n");
        return 0;
    }
    else
    {
       temp= arr[front]; 
        for(i=0;i<n;i++)
            arr[i] = arr[i+1];
        rear--;
        return  temp;
    }

}

int isEmpty()
{
    if(rear == 0)
        return 1;
    else
        return 0;
}


int peek(int *arr)
{
    return arr[front];
}

void display(int *arr)
{
   int i;

   if(isEmpty())
        printf("\nQUEUE IS EMPTY!!\n");
    else
   {
       printf("\nQUEUE ELEMENTS :-  "); 
        for(i=0;i<rear;i++)
            printf("%d   ",arr[i]);
   }
}


