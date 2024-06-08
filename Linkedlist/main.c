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



// Initialize node
struct node makenode(char x)
{
    struct node temp;
    temp.data = x;
    return temp;
}

//Search function checks the availability of a character in the list
bool searchLinkedList(struct linkedlist *l, char a)
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
    int result = searchLinkedList(l, tolower(n->data));
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


// counts number of dublicated characters, numbers & whitespaces
size_t dublicatesCounter(struct linkedlist *l, char s){

        struct node *x = (struct node *) malloc(sizeof(struct node));
        *x = makenode(tolower(s));
        prependNode(l, x);
        return l->length;
}

size_t dublicatesRegister(struct linkedlist *l, char *s){

    for (size_t i = 0; i < strlen(s); i++) {
    printf("iterating through %c \n", *(s+i));
      for (size_t i2 = i+1; i2 < strlen(s); i2++) {
        int result = compare(tolower(*(s + i)), tolower(*(s + i2)));
      if (result == 1){
       printf("comparison result of %c and %c is  %d \n", *(s + i), *(s + i2), result);
       printf("number of dublicates are now %zu :", dublicatesCounter(l, *(s +i )));

       break;
       }
      }
  }

  return l->length;
}

