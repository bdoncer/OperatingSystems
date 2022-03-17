#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "task3_dir.h"
#include "task3_nftw.h"


int main(int argc, char ** argv) {
    char *path = malloc(sizeof (char )*1000);
    if (argc == 1){
        printf("podaj sciezke do katalogu\n");
        scanf("%s",path);
        printf("%s", path);
    }
    if (argc == 2){
        path = argv[1];
    }
    if (argc != 2 && argc != 1){
        printf("wprowadz dobre argumenty :(((");
        exit(1);
    }
    char true_path[1000];

    realpath(path,true_path);
    run_nftw(true_path);
    //run(true_path)

}