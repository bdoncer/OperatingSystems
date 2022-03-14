#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "task3.h"


char **blocks;
int *free_indexes;
int size;

void make_array(int tmp_size){
    size = tmp_size;
    blocks = (char**) calloc(tmp_size, sizeof(char*));
    free_indexes = calloc(tmp_size,sizeof(int));
}

int write_from_file(){
    FILE *tmp;
    tmp = fopen("tmpFile","r");
    fseek(tmp, 0L, SEEK_END);
    long sz = ftell(tmp);
    rewind(tmp);
    char *from_file;
    from_file = calloc(sz,sizeof(char));
    fread(from_file, sizeof(char), sz, tmp);
    fclose(tmp);
    remove("tmpFile");
    int ind = are_free_before_ind();
    if (ind != -1){
        blocks[ind] = from_file;
        free_indexes[ind] = 1;
        return ind;
    }
    else{
        printf("%s","bro dont do it");
        return -1;
    }

}

int are_free_before_ind(){
    for(int i = 0;i<size;i++){
        if(free_indexes[i] == 0){
            return i;
        }
    }
    return -1;
}

void count_text_one_file(char file[]){
    char wc[100] = "wc ";
    char save[100] = " >> ";
    char file2[100] = "tmpFile";
    FILE *out=fopen(file2,"a");
    strcat(wc,file);
    strcat(save,file2);
    strcat(wc,save);
    system(wc);
    fclose(out);
}

void count_text(char files[][100], int n){
    for(int i = 0;i<n;i++){
        count_text_one_file(files[i]);
    }
}


int delete_block(int index)
{
    free(blocks[index]);
    blocks[index] = NULL;
    free_indexes[index] = 0;
    return 0;
}
