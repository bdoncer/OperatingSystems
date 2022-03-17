#include <stdio.h>
#include <stdlib.h>
#include "task2_lib.h"
#include "task2_sys.h"

int main(int argc, char *argv[]) {
    char *x_tab;
    char x;
    char *file_name = calloc(50,sizeof(char));

    if (argc == 1){
        printf("podaj znak\n");
        scanf("%c",&x);
        printf("podaj nazwe pliku\n");
        scanf("%s",file_name);
    }
    if (argc == 3){
        x_tab = argv[1];
        file_name = argv[2];
        x = x_tab[0];
    }
    if (argc != 3 && argc != 1){
        printf("wprowadz dobre argumenty :(((");
        exit(1);
    }



    //lib
    count(x,file_name);
    //sys
    //count_sys(x,file_name);

}