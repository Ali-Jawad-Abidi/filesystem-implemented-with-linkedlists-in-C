#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dir.h"
#include "file.h"

//Directory structure


char* get_name_dir(dir *f) {
    return f->name;
}
int get_size_dir() {
    return sizeof(dir);
}

LinkedList *get_files(dir *_this) {
    Node* node = _this->list.head;
    LinkedList p= createLinkedList();
    LinkedList *l=&p;
    void * item;
    while (node != NULL) {
    	
        if (node->isdir==0)
        {
        	item=node->f;
            add(l,item,0);
			//puts("hello");
        }
        node=node->next;
    }
    return l;
}
LinkedList *get_dirs(dir *_this) {
    Node* node = _this->list.head;
    LinkedList p= createLinkedList();
    LinkedList *l=&p;
    void * item;
    while (node != NULL) {
        if (node->isdir==1)
        {	
        	item=node->f;
            add(l,item,1);

        }
        node=node->next;
    }
    return l;
}
dir * cd(char* name,dir* cur_dir) {
	int result = strcmp(name, "..");
  LinkedList t;
	if(!result) {
    	
        return cur_dir->parent;
    }
    
    
    Node* node=cur_dir->list.head;


    while(node!=NULL) {
        if((node->isdir==1)&&(((dir*)node->f)->name==name)) {
            //printf("%d",&((dir*)node->f)->list);
             t=((dir*)node->f)->list;
            //cur_dir=&(((dir*)node->f)->list);

//            printf("%s\n\n\n\n",((dir*)node->f)->name);
//            printf("Hello");

            break;
        }
        node=node->next;
    }
    return ((dir*)node->f);


}

dir* create_dir(char * n, dir* cur_dir) {
	if(cur_dir!=NULL){
	
	Node* node = cur_dir->list.head;
    while (node != NULL) {
    	
        if ((node->isdir==1)&&(((dir*)node->f)->name==n))
        {
        	printf("Error: \"%s\" Directory already exists\n",n);
            return NULL;

        	}
        node=node->next;
    	}
    	dir * temp = (dir*)malloc(sizeof(dir));
    temp->name=n;
    temp->isdir=1;
    temp->list=createLinkedList();
    if (cur_dir!=NULL) {
        add(&cur_dir->list,(void*)temp,temp->isdir);
        temp->parent=cur_dir;
    }
    else {
        temp->parent=NULL;
    }
    //printf("Directory address:0x%x\t\t parent address:0x%x \n",&(temp->list),temp->parent);
    return temp;
	}
	else{
	
	
	
	
    dir * temp = (dir*)malloc(sizeof(dir));
    temp->name=n;
    temp->isdir=1;
    temp->list=createLinkedList();
    if (cur_dir!=NULL) {
        add(&cur_dir->list,(void*)temp,temp->isdir);
        temp->parent=cur_dir;
    }
    else {
        temp->parent=NULL;
    }
    //printf("Directory address:0x%x\t\t parent address:0x%x \n",&(temp->list),temp->parent);
    return temp;
	}
}


void ls(dir *_this){
	printf("(-) Directory\n(#) Files\n");
	dir * d= _this;
	if(d==NULL)
		return;
		
	while(d->parent!=NULL){
		d=d->parent;
	}
	
	ls1(d,_this,d);
	
}

void ls1 (dir * start,dir * cur_dir,dir *root) {
	char *pz=(char*)calloc(50,sizeof(char));
	dir * d= start;	
	Node* node = d->list.head;
	int t;
    while (node != NULL) {
        if (node->isdir==0)
        {
        	
         	while(d->name!=root->name){
         		strcat(pz,"\t");
    		d=d->parent;
    		
		}
		
			printf("%s#%s\n",pz,((file *)node->f)->name);
			for(t=0;t<10;t++){
					//printf("name",((unsigned char *)node->f)[t]);	
			}
			//printf("hello");
			
			
         	 
        }
        else{
        	while(d->name!=root->name){
    		strcat(pz,"\t");
    		d=d->parent;
    		
		}
            printf("%s-%s\n",pz,(((dir *)node->f)->name));
        	ls1((dir *)node->f,cur_dir,root);
        	
        	
            
        }
        
        
        node = node->next;

    }
    if(start==cur_dir)
        	return;
}


