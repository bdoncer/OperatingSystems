#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include "task2_lib.h"
#include "math.h"

float count_function(float x){
    return 4/(x*x+1);
}
float count_integral(float width, int n,int type){
    int op_ctr = 1/width;
    int op_per_process = op_ctr/n;
    int additional = op_ctr%n;
    int status = 0;
    pid_t wpid;
    float res = 0;
    for (int i = 0; i < n; ++i) {
        if (fork() == 0){
            int op_for_this_process = op_per_process;
            int op_up_to_now = i*op_per_process;
            if(op_up_to_now != 0){
                op_up_to_now += additional;
            }
            else{
                op_for_this_process += additional;
            }
            for (int k = 0; k < op_for_this_process; ++k) {
                res += count_function((op_up_to_now + k + 1) * width) * width;

            }
            char nr[10];
            char file_name[100] = "w";
            char txt[10] = ".txt";
            sprintf(nr, "%d", i+1);
            strcat(file_name,nr);
            strcat(file_name,txt);
            FILE *out=fopen(file_name,"w");
            fprintf(out, "%f", res);
            fclose(out);
            exit(0);
        }
    }
    //https://stackoverflow.com/questions/19461744/how-to-make-parent-wait-for-all-child-processes-to-finish
    while ((wpid = wait(&status)) > 0){
    }
    res = 0;
    for(int i = 0;i < n;i++){
        char name[100] = "w";
        char nr[10];
        char end[100] = ".txt";
        sprintf(nr, "%d", i+1);
        strcat(name,nr);
        strcat(name,end);
        FILE *out=fopen(name,"r");
        char bufor[100];
        fread( bufor, sizeof( char ), 100, out);
        res += strtod(bufor,NULL);
        fclose(out);
    }
    if (type == 0){
        printf("%f",res);
    }

    return res;


}
