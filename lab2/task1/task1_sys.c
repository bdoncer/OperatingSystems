#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include "task1_sys.h"

void copy_from_file_sys(char *first_file, char* second_file){
    char c;
    int in,out;
    int sem;
    int i;
    char *line;
    in = open(first_file, O_RDONLY);
    out=open(second_file,O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    while(read(in,&c,1)==1){
        line = calloc(256,sizeof(char));
        line[0] = c;
        i = 1;
        sem = 0;
        while(c != '\n' && read(in,&c,1)==1){
            line[i] = c;
            if (line[i] != ' '){
                sem = 1;
            }
            i++;
        }
        if (sem == 1){
            write(out,line,(i)*sizeof(char));
        }
    }

    close(in);
    close(out);
}