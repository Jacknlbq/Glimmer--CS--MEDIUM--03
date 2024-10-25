#include<stdio.h>
#include<string.h>
#include <dirent.h>
#include<stdlib.h>
#include <sys/stat.h>


void printf_work_directory(const char *current_path,struct stat statbuf)
{
     DIR *dir;
     struct dirent *entry;

     if(!(dir = opendir(current_path))) 
    {  
        perror("opendir");  
        exit(EXIT_FAILURE);  
    }  
    char full_path[1024];
      while ((entry = readdir(dir)) != NULL) {  
          
        if(entry->d_ino==statbuf.st_ino){
            snprintf(full_path, sizeof(full_path), "/%s", entry->d_name); 
           break;
        }
      }
    struct stat statbuf_above;
    if (stat(current_path, &statbuf_above) == -1) {  
            perror("stat");   
        }
    char above_path[100];
    snprintf(above_path, sizeof(full_path), "../%s", current_path);
    //自调用，向上找
    if(statbuf_above.st_ino!='/')
    printf_work_directory(above_path,statbuf_above);

   printf("%s",full_path);

}



int main()
{
    struct stat statbuf;
    if (stat(".", &statbuf) == -1) {  
            perror("stat");   
        }
        printf_work_directory(".",statbuf);
     return 0;
}