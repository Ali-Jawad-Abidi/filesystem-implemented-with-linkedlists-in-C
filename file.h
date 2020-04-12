#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dir.h"
//#include "linkedlist.h"
//#include "linkedlist.c"




typedef struct File {
    //variables
    char* name;
    int size;
    bool isdir;
    char* date;
} file;


file *create_file(char* name,int size, char *date, dir * cur_dir);
int get_size_file(file *a);
char* get_name_file(file *a);
char* get_date(file *a);
LinkedList *get_files(dir *a);
void move(char*a,char*b, dir *c);
void rename1(char*a,char*b, dir *c);
file * rm(char * name, dir * _this);
#endif
