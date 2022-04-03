
#include "task3_lib.h"

#include "task3_lib.h"
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int is_text(char file_name[], char text[]){
    //https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c
    char * buffer = 0;
    long length;
    FILE * f = fopen (file_name, "rb");
    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    }

    if (buffer)
    {
        if(strstr(buffer, text) != NULL){
            return 0;
        }
    }
    return 1;
}


void count_directory(char *dir_path,char text[], int depth){
    struct dirent* res;
    DIR *dir;
    pid_t wpid;
    int status = 0;
    dir = opendir(dir_path);
    struct stat buf;
    res = readdir(dir);
    if (depth == 0){
        return;
    }
    while (res != NULL){
        if (strcmp(res->d_name,".") != 0 && strcmp(res->d_name,"..") != 0){
            char* whole_path = calloc(strlen(dir_path) + 100, sizeof (char));
            strcat(whole_path, dir_path);
            strcat(whole_path, "/");
            strcat(whole_path, res->d_name);
            stat(whole_path,&buf);

            if (S_ISREG(buf.st_mode)){
                printf("\n%s\n",whole_path);
                printf("Child pid: %d Parent pid: %d\n",  getpid(), getppid());
                if (is_text(whole_path,text) == 0){
                    printf("Udało się znaleźć tekst\n");
                }
                else{
                    printf("Nie udało się znaleźć tekstu\n");
                }

            }
            else if (S_ISDIR(buf.st_mode)){
                if(fork() == 0){
                    count_directory(whole_path,text,depth-1);
                    exit(0);
                }
                while ((wpid = wait(&status)) > 0){
                }

            }
        }

        res = readdir(dir);
    }
    closedir(dir);
}

