#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>
#include "task2_sys.h"

void count_sys(char x, char* file_name){
    char c;
    int f;
    int sem;
    int i;
    int all = 0;
    int lines = 0;
    f = open(file_name, O_RDONLY);
    while(read(f,&c,1)==1){
        sem = 0;
        if (c == x){
            all += 1;
            sem = 1;
        }
        i = 1;
        while(c != '\n' && read(f,&c,1)==1){
            if (c == x){
                all += 1;
                sem = 1;
            }
            i++;
        }
        if (sem == 1){
            lines += 1;
        }
    }

    close(f);
    printf("Liczba wystapien: ");
    printf("%d\n",all);
    printf("Liczba wierszy: ");
    printf("%d\n",lines);


}