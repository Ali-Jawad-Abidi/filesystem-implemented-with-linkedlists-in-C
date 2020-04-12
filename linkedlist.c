#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"



//Node struct



void add (LinkedList* _this, void* item,bool v) {
    // index out of list size


    Node* node = _this->head;

    if (node==NULL) {

        Node* newNode = createNode(item,v);
        _this->head=newNode;

    }// loop until the position
    else {
        while (node->next!= NULL) {
            node = node->next;
        }
        // insert new node to position
        Node* newNode = createNode(item,v);
        node->next=newNode;
        node->next->next=NULL;

    }
    _this->size++;

}
void  get (LinkedList* _this) {

}
void _remove (LinkedList* _this) {
    // list is empty
    Node* node = _this->head;
    while (node->next->f != NULL) {
        node = node->next;
    }

    // remove from head



    node->next=node->next->next;
    _this->size--;
    return ;

}


void  displaylinkedlist (LinkedList* _this) {
    Node* node = _this->head;

    while (node != NULL) {
        if (node->isdir==0)
        {
           	 //file *f=(file *)node->f;
         	 printf("file\n");//,f->name);
         	 
        }
        else{
        	printf("Dir\n");//,f->name);
            //printf("%s\n",(((dir *)node->f)->name));
            
        }
        node = node->next;

    }
}


LinkedList createLinkedList () {
    LinkedList list;
    list.head = NULL;
    //list.add = &add;
    //list.get = &get;
    //list.remove = &_remove;
    //list.displaylinkedlist = &displaylinkedlist;
    //list.createNode = &createNode;
    return list;
}

Node* createNode (void * p,bool v) {
    Node* node = (Node*) malloc (sizeof(Node));
    node->f = p;
    node->next = NULL;
    node->isdir=v;
    return node;
}
