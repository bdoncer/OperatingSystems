#include <bits/types/FILE.h>
#include <stdio.h>
#include "task2_lib.h"

void count(char x, char* fileName){
    FILE *f;
    f = fopen(fileName,"r");
    //https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int sem;
    int i;
    int all = 0;
    int lines = 0;
    while ((read = getline(&line, &len, f)) != -1) {
        sem = 0;
        i = 0;
        while(line[i] != '\n'){
            if(line[i] == x){
                sem = 1;
                all += 1;
            }
            i++;
        }
        if (sem == 1){
            lines += 1;
        }
    }
    fclose(f);
    printf("Liczba wystapien: ");
    printf("%d\n",all);
    printf("Liczba wierszy: ");
    printf("%d\n",lines);
}