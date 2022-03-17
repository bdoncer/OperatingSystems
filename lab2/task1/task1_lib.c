#include <bits/types/FILE.h>
#include <stdio.h>
#include "task1_lib.h"

void copy_from_file(char *first_file, char* second_file){
    FILE *in;
    FILE *out;
    in = fopen(first_file,"r");
    out = fopen(second_file,"w");
    //https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int sem;
    int i;
    while ((read = getline(&line, &len, in)) != -1) {
        sem = 0;
        i = 0;
        while(line[i] != '\n'){
            if(line[i] != ' '){
                sem = 1;
                break;
            }
            i++;
        }
        if (sem == 1){
            fputs(line, out);
        }
    }
    fclose(in);
    fclose(out);
}