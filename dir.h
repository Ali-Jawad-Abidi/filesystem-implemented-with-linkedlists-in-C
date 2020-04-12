#ifndef DIR_H
#define DIR_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"


typedef struct Dir {
    //variables
    char* name;
    bool isdir;
    LinkedList list;
    struct Dir *parent;

} dir;


char *get_name_dir(dir *);
int get_size_dir();
LinkedList *get_dirs(dir *);
dir * create_dir(char * name, dir * );
dir* cd(char* name,dir* cur_dir);
void ls (dir* _this);
void ls1 (dir * start,dir * cur_dir,dir * root);

#endif
