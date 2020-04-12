#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "linkedlist.h"
//#include "dir.h"
#include "file.h"
//#include "file.c"

#include <time.h>

int main (int argc,char ** argv) {	
	time_t t=time(NULL);
    dir * cur_dir = create_dir("root",NULL);	//creating the root directory	
    if(cur_dir==NULL){
    	puts("Could not create root directory. Exiting....");
    	return 1;
	}
    dir *root=cur_dir;
	file*f=create_file("root_file_1",1000,strtok(ctime(&t),"\n"),cur_dir);
	//printf("%d\n",get_size_file(f));						//size of the file
    //printf("%s\n",get_name_file(f)); 		// name of the file
					//creating a test directory inside root
    //create_dir("temp",cur_dir);				//creating same directory again throws an error
	create_file("root_file_2",100,strtok(ctime(&t),"\n"),cur_dir);		//creating another test file inside root
    //create_file("myfile1",100,strtok(ctime(&t),"\n"),cur_dir);		//creating same file again throws an error
						//creating another directory inside root
    
    //move("myfile","temp2",cur_dir);					//Moving myfile from root to root/temp2/
    //ls(cur_dir);	
    create_dir("root_dir_1",cur_dir);
	create_dir("root_dir_2",cur_dir);
	//create_file("myfile2",100,strtok(ctime(&t),"\n"),cur_dir);		//creating a file inside root								//listing files and directories of the current directory i-e root
    dir * temp=cur_dir=cd("root_dir_1",cur_dir);						//moving from root to root/temp

    	
	create_file("dir_1_file_1",100,strtok(ctime(&t),"\n"),cur_dir);
	create_file("dir_1_file_2",100,strtok(ctime(&t),"\n"),cur_dir);		//creating a file inside root				//creating a test directory in root/temp by the name temp2
	create_dir("dir_1_dir_1",cur_dir);
	cur_dir=cd("dir_1_dir_1",cur_dir);
	create_file("dir_1_dir_1_file_1",100,strtok(ctime(&t),"\n"),cur_dir);				//creating a test directory in root/temp by the name temp2
	create_file("dir_1_dir_1_file_2",100,strtok(ctime(&t),"\n"),cur_dir);
	//move("myfile","temp2",cur_dir);					//moving myfile from root/temp to root/temp/temp2. Error since the file doesnot exist
    //ls(cur_dir);				
	//cur_dir=cd("temp2",cur_dir);
	//ls(cur_dir);					//listing files and directories of the current directory i-e root/temp
    //cur_dir=cd("..",cur_dir);						//going back to the previous directory i-e root
    //cur_dir=cd("..",cur_dir);
    //rename1("myfile","renamedfile",cur_dir);		//renaming myfile in root to renamedfile
    //ls(cur_dir);									//listing files and directories of the current directory i-e root/temp
    //cur_dir=cd("temp2",cur_dir);					//moving from root to root/temp2
    
    //rm("myf",root); 				//removed testfil from root
    //ls(root);
	ls(cur_dir);									//listing files and directories of the current directory i-e root/temp
    
    
    
	
	system("PAUSE");
	return 0;								//system halt

}

