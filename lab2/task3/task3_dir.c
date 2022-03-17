#include "task3_dir.h"
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

int file_ctr = 0;
int dir_ctr = 0;
int char_dev_ctr = 0;
int block_dev_ctr = 0;
int fifo_ctr = 0;
int slink_ctr = 0;
int socket_ctr = 0;
struct dirent* res;

void run(char *dir_name){
    count_directory(dir_name);
    printf("Ilosc plikow regularnych: %d\n",file_ctr);
    printf("Ilosc katalogow: %d\n",dir_ctr);
    printf("Ilosc urzadzen znakowych: %d\n",char_dev_ctr);
    printf("Ilosc urzadzen blokowych: %d\n",block_dev_ctr);
    printf("Ilosc potokow: %d\n",fifo_ctr);
    printf("Ilosc linkow symbolicznych: %d\n",slink_ctr);
    printf("Ilosc soketow: %d\n",socket_ctr);
}

void count_directory(char *dir_path){

    DIR *dir;
    dir = opendir(dir_path);
    struct stat buf;
    res = readdir(dir);

    while (res != NULL){
        if (strcmp(res->d_name,".") != 0 && strcmp(res->d_name,"..") != 0){
            char* whole_path = calloc(strlen(dir_path) + 100, sizeof (char));
            strcat(whole_path, dir_path);
            strcat(whole_path, "/");
            strcat(whole_path, res->d_name);
            stat(whole_path,&buf);
            printf("nazwa pliku: %s\n", res->d_name);
            printf("sciezka bezwzgledna: %s\n", whole_path);
            printf("liczba dowiazan: %lu\n", buf.st_nlink);
            printf("rozmiar w bajtach: %lu\n", buf.st_size);
            printf("data ostatniego dostepu: %ld\n", buf.st_atime);
            printf("data ostatniej modyfikacji: %ld\n", buf.st_mtime);
            if (S_ISREG(buf.st_mode)){
                printf("rodzaj pliku to plik regularny\n\n");
                file_ctr += 1;
            }
            else if (S_ISDIR(buf.st_mode)){
                printf("rodzaj pliku to katalog\n\n");
                dir_ctr += 1;
                count_directory(whole_path);

            }
            else if (S_ISCHR(buf.st_mode)){
                printf("rodzaj pliku to urzadzenie znakowe\n\n");
                char_dev_ctr += 1;
            }
            else if (S_ISBLK(buf.st_mode)){
                printf("rodzaj pliku to urzadzenie blokowe\n\n");
               block_dev_ctr += 1;
            }
            else if (S_ISFIFO(buf.st_mode)){
                printf("rodzaj pliku to potok\n\n");
                fifo_ctr += 1;
            }
            else if (S_ISLNK(buf.st_mode)){
                printf("rodzaj pliku to link symboliczny\n\n");
                slink_ctr += 1;
            }
            else if (S_ISSOCK(buf.st_mode)){
                printf("rodzaj pliku to soket\n\n");
                socket_ctr += 1;
            }
            else{
                printf("rodzaj pliku nieznany\n\n");
            }
        }
        res = readdir(dir);
    }
    closedir(dir);
}