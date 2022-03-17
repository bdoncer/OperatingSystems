#define _XOPEN_SOURCE 500
#include <ftw.h>
#include "task3_nftw.h"
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

int file_ctr2 = 0;
int dir_ctr2 = 0;
int char_dev_ctr2 = 0;
int block_dev_ctr2 = 0;
int fifo_ctr2 = 0;
int slink_ctr2 = 0;
int socket_ctr2 = 0;


void run_nftw(char *dir_name){
    count_directory_nftw(dir_name);
    printf("Ilosc plikow regularnych: %d\n",file_ctr2);
    printf("Ilosc katalogow: %d\n",dir_ctr2);
    printf("Ilosc urzadzen znakowych: %d\n",char_dev_ctr2);
    printf("Ilosc urzadzen blokowych: %d\n",block_dev_ctr2);
    printf("Ilosc potokow: %d\n",fifo_ctr2);
    printf("Ilosc linkow symbolicznych: %d\n",slink_ctr2);
    printf("Ilosc soketow: %d\n",socket_ctr2);
}

int single_file(const char* whole_path, const struct stat* buf,int sem, struct FTW* ftw){
    char *file_name = calloc(100,sizeof(char));
    int index = 0;
    for(int i = 0;i<strlen(whole_path);i++){
        if(whole_path[i] == '/'){
            index = i;
        }
    }
    for(int i = 0;i<index;i++){
        file_name[i] = whole_path[i+index];
    }
    printf("nazwa pliku: %s\n", file_name);
    printf("sciezka bezwzgledna: %s\n", whole_path);
    printf("liczba dowiazan: %lu\n", buf->st_nlink);
    printf("rozmiar w bajtach: %lu\n", buf->st_size);
    printf("data ostatniego dostepu: %ld\n", buf->st_atime);
    printf("data ostatniej modyfikacji: %ld\n", buf->st_mtime);
    if (S_ISREG(buf->st_mode)){
        printf("rodzaj pliku to plik regularny\n\n");
        file_ctr2 += 1;
    }
    else if (S_ISDIR(buf->st_mode)){
        printf("rodzaj pliku to katalog\n\n");
        dir_ctr2 += 1;

    }
    else if (S_ISCHR(buf->st_mode)){
        printf("rodzaj pliku to urzadzenie znakowe\n\n");
        char_dev_ctr2 += 1;
    }
    else if (S_ISBLK(buf->st_mode)){
        printf("rodzaj pliku to urzadzenie blokowe\n\n");
        block_dev_ctr2 += 1;
    }
    else if (S_ISFIFO(buf->st_mode)){
        printf("rodzaj pliku to potok\n\n");
        fifo_ctr2 += 1;
    }
    else if (S_ISLNK(buf->st_mode)){
        printf("rodzaj pliku to link symboliczny\n\n");
        slink_ctr2 += 1;
    }
    else if (S_ISSOCK(buf->st_mode)){
        printf("rodzaj pliku to soket\n\n");
        socket_ctr2 += 1;
    }
    else{
        printf("rodzaj pliku nieznany\n\n");
    }
    return 0;
}

void count_directory_nftw(char *dir_path){
    nftw(dir_path, (__nftw_func_t) single_file, 1000, FTW_PHYS);
}