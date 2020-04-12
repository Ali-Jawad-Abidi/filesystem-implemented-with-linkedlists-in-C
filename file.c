#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"

//#include "linkedlist.h"
//#include "linkedlist.c"



void rename1(char*a,char*b, dir * _this) {

Node* node = _this->list.head;


    while (node != NULL) {
        if ((node->isdir==0)&&(((file*)node->f)->name==a))
        {
            ((file*)node->f)->name=b;

        }
        node=node->next;
    }
    if (node==NULL){
    	printf("\"%s\" does not exist\n",a);
	}
}
	
	
    
file * rm(char * name,dir * _this){
	Node* node = _this->list.head;
	file * z;
	if((node->isdir==0)&&(((file*)node->f)->name==name)){
		_this->list.head=node->next;
		return (file*)node->f;
	}
	while (node->next != NULL) {
    
        if (node->next->isdir==0)
        {
            z=(file *)node->next->f;
                if(z->name==name){
            		node->next=node->next->next;
            		return z;
                  
                }
        }
        node=node->next;
        	}
        if(node==NULL){
        	printf("File \"%s\" doesnot exisst here",name);
        	return NULL;
		}
		
	
	
}
void move(char*a,char*b,dir*_this) {
file * z=NULL;
dir *j=NULL;
Node * temp=NULL;

    Node* node = _this->list.head;
    if ((node->isdir==0)&&((((file *)node->f)->name==a))){
            z=(file *)node->f;
      }
    else{     
    //printf("%d",node->item);
    while (node->next != NULL) {
    
        if (node->next->isdir==0)
        {
            z=(file *)node->next->f;
                if(z->name==a){
            
                  break;
                }
        temp=node;
        }
        node=node->next;
        	}
        }
        if(node->next==NULL){
        	printf("\"%s\" not found in current directory\n",a);
        	return;
		}
        Node *node1= _this->list.head;
        while(node1!=NULL){
            if(node1->isdir==1){
                j=(dir*)node1->f;
                if(j->name==b){
                   break;
            }}
            node1=node1->next;
        }
        if(node1==NULL){
        	printf("\"%s\" not found in current directory\n",b);
        	return;
		}
       create_file(z->name,z->size,z->date,j);
        if(node==_this->list.head)
           _this->list.head=_this->list.head->next;
        else
       node->next=node->next->next;
            

}















int get_size_file(file *f) {
    return f->size;
}
char* get_name_file(file *f) {
    return f->name;
}
char* get_date(file *f) {
    return f->date;
}




file * create_file(char* name,int size, char *date,dir *cur_dir) {
	Node* node = cur_dir->list.head;
    while (node != NULL) {
    	
        if ((node->isdir==0)&&(((file*)node->f)->name==name))
        {
        	printf("Error: \"%s\" File already exists\n",name);
            return NULL;

        	}
        node=node->next;
    	}
	
    file * temp;
    temp=(file*)malloc(sizeof(file));
    temp->name=name;
    temp->size=size;
    temp->date=date;
    temp->isdir=0;
    add(&cur_dir->list,(void *)temp,temp->isdir);
    return temp;

}

