#include <stdio.h>
#include <stdlib.h>
#include "task1_lib.h"


int main(int argc, char *argv[]) {
    int n;
    if (argc == 1) {
        printf("podaj ilosc procesow potomnych\n");
        scanf("%d", &n);
    }
    else if(argc == 2){
        n = atoi(argv[1]);
    }
    else{
        printf("wprowadz dobre argumenty :(((");
        exit(1);
    }

    make_processes(n);

}