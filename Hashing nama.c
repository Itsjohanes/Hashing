#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define size 5
//LINKED LIST
typedef struct node
{
    char data[10];
    struct node *next;
}node;

node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(char masukan[])
{
    //create a newnode with value
     node *newNode;
     newNode = (node*) malloc(sizeof( node));
    int value = 0;
    int i;
    for(i = 0;i<strlen(masukan);i++)
    {
        value  = value + (int)masukan[i];

    }
    //newNode->data = value;
    strcpy(newNode->data,masukan);
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
       node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
         node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp != NULL)
        {
            printf("%s -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    //init array of list to NULL
    init();

    insert("A");


    print();

    return 0;
}

