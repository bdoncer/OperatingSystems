#include <stdio.h>
#include <stdlib.h>
#include "task2_lib.h"

int main(int argc, char *argv[]) {
    int n;
    float width;
    if (argc == 1) {
        printf("podaj szerokosc prostokata\n");
        scanf("%f", &width);
        printf("podaj ilosc procesow potomnych\n");
        scanf("%d", &n);
    }
    else if(argc == 3){
        width = atof(argv[1]);
        n = atoi(argv[2]);
    }
    else{
        printf("wprowadz dobre argumenty :(((");
        exit(1);
    }

    if(1/width < n){
        printf("za malo procesow :(((");
        exit(1);
    }

    count_integral(width,n,0);

}
