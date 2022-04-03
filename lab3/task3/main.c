//sciezka,tekst,glebokosc

#include <stdio.h>
#include <stdlib.h>
#include "task3_lib.h"


int main(int argc, char *argv[]) {
    char *dir_path = malloc(sizeof (char )*1000);
    char *text = malloc(sizeof (char )*1000);
    int depth;
    if (argc == 1) {
        printf("podaj sciezke\n");
        scanf("%s", dir_path);
        printf("podaj tekst do wyszukania\n");
        scanf("%s", text);
        printf("podaj glebokosc\n");
        scanf("%d", &depth);
    }
    else if(argc == 4){
        dir_path = argv[1];
        text = argv[2];
        depth = atoi(argv[3]);
    }
    else{
        printf("wprowadz dobre argumenty :(((");
        exit(1);
    }

    count_directory(dir_path, text, depth);





}

