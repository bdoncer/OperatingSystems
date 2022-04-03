#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "task1_lib.h"


void make_processes(int n){
    for(int i = 0;i < n;i++){

        if (fork() == 0){
            printf("Child pid: %d Parent pid: %d\n",getpid(),getppid());
            exit(0);
        }
    }
}
