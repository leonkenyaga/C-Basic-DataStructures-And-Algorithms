#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


struct Treenode
{
    int data;
    struct Treenode *left;
    struct Treenode *right;
};



// Initialize Treenode
struct Treenode *makenode(int i)
{
    struct Treenode *T= (struct Treenode *) malloc(sizeof(struct Treenode));
   
    T->data = i;
    
    return T;
}

//Search function checks the availability of a character in the list


//Prepend adds a node to the Tree




//PrintTree Traverses and prints the entire tree
