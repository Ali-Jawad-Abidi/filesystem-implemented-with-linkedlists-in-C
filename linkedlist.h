#ifndef linkedlist_H
#define linkedlist_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    //variables
    void *f;
    bool isdir;
    struct node* next;
} Node;

//LinkedList struct
typedef struct linkedlist {
    //variables
    Node* head;
    int size;

} LinkedList;


void add (LinkedList* _this, void* item,bool);
void  get (LinkedList* _this);
void _remove (LinkedList* _this);
void displaylinkedlist (LinkedList* _this);
Node* createNode (void *,bool);
LinkedList createLinkedList ();
#endif
