//linked list
#include <stdio.h>
#include <stdlib.h>

void insert(int ele);
void  delete();
int  isEmpty();
void display();

int size = 0;

struct node
{
    int data;
    struct node * next;
} *head = NULL ;

void main()
{
    int ch,ele,pos;  
    while(1)
    {
        printf("\n[1] INSERT\n[2] DELETE\n[3] EXIT PROGRAM\n");
        printf("\nENTER YOUR CHOICE => ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nENTER ELEMENT TO ADD =>  ");
                    scanf("%d",&ele);
                    insert(ele);
                    display();
                    break;

            case 2: delete();
                    display();
                    break;

            case 3 :exit(0);
                    break;                

            default:printf("\nINVALID CHOICE TRY AGAIN!!!!! ");
        }
    }
}

void insert(int ele)
{
    int pos ,i;
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL)
        printf("\nUNABLE TO ALLOCATE MEMORY!!!!!");
   
    else
    {
        printf("\nENTER POSITION TO INSERT DATA => ");
        scanf("%d" ,&pos);

        struct node *temp;

        if(isEmpty())
        {
                printf("\nLIST IS EMPTY INSERT ELEMENT AS 1ST NODE!!!!!\n");
                   
                newNode->data = ele;
                newNode->next = NULL;
                head = newNode;
                //tail = newNode;
        }  
        else
        {
            if(pos == 1)
            {
                newNode->data = ele;
                newNode->next = head;
                head = newNode;
            }
            else if(pos == size+1)
            {
                temp = head;
               
                while(temp->next != NULL)
                    temp= temp->next;

                newNode->data = ele;
                newNode->next = NULL;
                temp->next = newNode;
            }
            else if(pos > 1 && pos <=size)
            {
                temp = head;
                for(i=1;i<pos-1;i++)
                    temp = temp->next;

                newNode->data = ele;
                newNode->next=temp->next;
                temp->next = newNode;
            }
            else
                printf("\nINVALID POSITION!!!!!!! ");
        }
        size++;
               
    }

    printf("\nELEMENT INSERT");
}

int isEmpty()
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

void delete()
{
    int pos ,i,ele;
    struct node *temp;


    if(isEmpty())
    {
        printf("\nLIST IS ALREADY EMPTY\n");
        return ;        
    }  
    else
    {
       
        printf("\nENTER POSITION TO DELETE DATA!!!! ");
        scanf("%d" ,&pos);
       
        if(pos == 1)
        {
            ele = head->data;
            temp = head;
            head = head->next;
            free(temp);
        }
        else if(pos == size+1)
        {
            temp = head;
               
            while(temp->next != NULL)
                temp= temp->next;
           
            ele = temp->data;
            free(temp);

        }
        else if(pos > 1 && pos <=size)
        {
            temp = head;
            for(i=1;i<pos-1;i++)
                temp = temp->next;

            ele = temp->data;
            temp->next = temp->next->next;
        }
        else
        {
            printf("\nINVALID POSITION ");
            size++;
        }
    }
    size--;
        //printf("\nSize : %d ",size) ;

    printf("\nELEMENT %d DELETED!!!",ele);
}

void display()
{
    struct node *temp;
    temp = head;
    if(isEmpty())
        printf("\nEMPTY LIST!!!!!");

    else
    {
        printf("\nELEMENTS => ");
        while(temp != NULL)
        {
            printf("%d   ",temp->data);
            temp = temp->next;
        }
    }
}
