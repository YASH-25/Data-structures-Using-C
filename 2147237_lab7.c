//hashing technique
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
#define sizeL 100

typedef struct node
{
    int index;
    int data;
} node;

node *head;
node *first = NULL;
// resetting array to -1
void arrayOfnode(node *array[])
{
    // node* ptr;
    int i = 0;
    node *temp;
    while (i < sizeL)
    {
        temp = (node *)malloc(sizeof(node));
        array[i] = temp;
        array[i]->index = i;
        array[i]->data = -1;
        i++;
    }
}

void hashinserting(node *array[], int key)
{
    int i;
    int index = ((2 * key) + 3) % sizeL;
    i = index;
    printf("\n%d", key);
    while (i < sizeL - 1)
    {
        printf("\n i value is:%d", i);
        if (array[i]->data == -1)
        {
            printf("\n i = %d \t index = %d", i, index);
            array[i]->data = key;
            break;
            // return 1;
        }
        else if (i == sizeL - 1)
        {
            printf("\n starting to search from begning");
            i = 0;
        }
        else if (i == index - 1)
        {
            printf("\n no space found in whole array");
            break;
        }

        i++;
    }
}

int hashsearch(node *array[], int key)
{
    int index = ((2 * key) + 3) % sizeL;
    int i = index;
    while (i < sizeL)
    {
        if (array[i]->data == key)
        {
            printf("\n Item found at position:%d", array[i]->index);
            return 1;
        }
        else if (i == sizeL - 1)
        {
            i = 0;
        }
        else if (i == index - 1)
        {
            return 0;
        }
        i++;
    }
    printf("\n Item not found !!");
    return 0;
}

void printwholearray(node *a[])
{
    int i;
    for (i = 0; i < sizeL; i++)
    {
        printf("\n%p\t%d\t%d", a[i], a[i]->index, a[i]->data);
        printf("\n---------------------");
    }
}
void fill_random(int array[], int length, int max)
{
    // loop through each index of the array... rand() % max will produce a
    // random number between 0 - (max-1), adding 1 will shift it to 1 - max
    srand(time(NULL));
    int i;
    for (i = 0; i < length; i++)
    {
        array[i] = (rand() % max) + 1;
    }
}

int main()
{
    int flag = 1;
    int choice;
    int data;
    node *stu_marks[100];
    arrayOfnode(stu_marks);
    //	hashinserting(stu_marks,50);
    //	hashinserting(stu_marks,150);
    //	hashinserting(stu_marks,250);
    //	printwholearray(stu_marks);
    while (flag)
    {
        printf("\nMenu");
        printf("\n----");
        printf("\n1.Hash insertion");
        printf("\n2.Hash search");
        printf("\n3.Print whole array");
        printf("\n4.Exit.");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the Data to insert: ");
            scanf("%d", &data);
            hashinserting(stu_marks, data);
            break;
        case 2:
            printf("\nEnter the search key:");
            scanf("%d", &data);
            if (hashsearch(stu_marks, data) == 0)
            {
                printf("\nCan't find the item in list");
            }
            break;
        case 3:
            printwholearray(stu_marks);
            break;
        case 4:
            flag = 0;
            return 0;
        default:
            printf("\nInvalid choice..Try again");
        }
    }
    return 0;
}