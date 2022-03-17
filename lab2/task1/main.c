#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "task1_lib.h"
#include "task1_sys.h"

int main(int argc, char **argv) {
    char *first_file = calloc(50,sizeof(char));
    char *second_file = calloc(50,sizeof(char));
    if (argc == 1){
        printf("podaj nazwe pliku, z ktorego chcesz skopiowac\n");
        scanf("%s",first_file);
        printf("podaj nazwe pliku, do ktorego chcesz skopiowac\n");
        scanf("%s",second_file);
    }
    if (argc == 3){
        first_file = argv[1];
        second_file = argv[2];
    }
    if (argc != 1 && argc != 3){
        printf("wprowadz dobre argumenty :(((");
        exit(1);
    }


    //lib
    copy_from_file(first_file,second_file);
    //sys
    //copy_from_file_sys(first_file,second_file);

}