#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "task1.h"

char **blocks;
int *free_indexes;
int size;
int array_allocated = 0;
int count_made = 0;

void make_array(int tmp_size){
    size = tmp_size;
    blocks = (char**) calloc(tmp_size, sizeof(char*));
    free_indexes = calloc(tmp_size,sizeof(int));
    array_allocated = 1;
}

int write_from_file(){
    if (count_made == 0){
        printf("you need to count_text first!");
        exit(1);
    }
    FILE *tmp;
    tmp = fopen("tmp_file","r");
    fseek(tmp, 0L, SEEK_END);
    long sz = ftell(tmp);
    rewind(tmp);
    char *from_file;
    from_file = calloc(sz,sizeof(char));
    fread(from_file, sizeof(char), sz, tmp);
    fclose(tmp);
    remove("tmp_file");
    int ind = are_free_before_ind();
    if (ind != -1){
        blocks[ind] = from_file;
        free_indexes[ind] = 1;
        return ind;
    }
    else{
        printf("%s","bro dont do it - not enough space :((");
        exit(1);
    }
    count_made = 0;

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
    if(array_allocated == 0){
        printf("you need to allocate memory first!");
        exit(1);
    }
    char wc[100] = "wc ";
    char save[100] = " >> ";
    char file2[100] = "tmp_file";
    FILE *out=fopen(file2,"a");
    strcat(wc,file);
    strcat(save,file2);
    strcat(wc,save);
    system(wc);
    fclose(out);
    count_made = 1;
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