#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


struct node
{
    char data;
    struct node *next;
};

struct linkedlist
{
    struct node *head;
    int length;
};

//Initialize linkedlist
struct linkedlist *makelist(){
return (struct linkedlist *) malloc(sizeof(struct linkedlist));
}

// Initialize node
struct node *makenode(char c)
{
    struct node *n= (struct node *) malloc(sizeof(struct node));
    n->data= c;
    return n;
}

//Search function checks the availability of a character in the list
bool Search(struct linkedlist *l, char a)
{

    printf("length2 is %d \n", l->length);
    if (l->length == 0)
    {

        return false;
    }

    // declare an integer and store the length of the linkedlist in it

    int length = l->length;

    // executes a while loop that reduces the integers value after every iteration
    struct node *previousTraversal = l->head;

    while (length != 0)
    {
        if (previousTraversal->data == a)
        {

            return true;
        }
        if (length > 1)
        {
            previousTraversal = previousTraversal->next;
        }

        length--;
    }

    return false;
}

void prependNode(struct linkedlist *l, struct node *n)
{
    printf("length1 is %d \n", l->length);
    int result = Search(l, tolower(n->data));
    printf("length3 is %d \n", l->length);
    if (result == 0)
    {
        n->next = l->head;
        l->head = n;
        l->length++;
        printf("entry not available, length increased to %d \n", l->length);
    }
    else
    {
        printf("entry available, length is %d \n", l->length);
    }
    printf("length4 is %d \n", l->length);
}

//recursively builds function stack to the first sdded character
void printListData(struct node *n)
{
    if (n->next != NULL)
        printListData(n->next);
    printf("%c", n->data);
    
}
//prints linkedlist in a first added to last added character order
void printLinkedlist(struct linkedlist *l){
    if (l->head !=NULL){
    printListData(l->head);
    }
    printf("\n");
}



