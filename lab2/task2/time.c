#include <stdio.h>
#include <stdlib.h>
#include "task2_lib.h"
#include "task2_sys.h"
#include <time.h>
#include <unistd.h>
#include <sys/times.h>


void write_to_report_single(FILE * raport, char* header,  struct tms time_count, clock_t time_count_real, struct tms time_count2, clock_t time_count_real2){
    fprintf(raport,"%s    %lf",header, (double) (time_count_real2 - time_count_real) / CLOCKS_PER_SEC );
    fprintf(raport,"            %lf",(double) (time_count2.tms_utime - time_count.tms_utime) / sysconf(_SC_CLK_TCK));
    fprintf(raport,"            %lf \n",(double) (time_count.tms_stime - time_count.tms_stime) / sysconf(_SC_CLK_TCK));
}


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

    struct tms time_count[5];
    clock_t time_count_real[5];
    FILE *raport;
    raport = fopen("pomiar_zad_2.txt","w");
    fprintf(raport,"%s","            REAL         USER         SYS\n");

    times(&time_count[0]);
    time_count_real[0] = clock();
    count(x,file_name);
    times(&time_count[1]);
    time_count_real[1] = clock();
    count(x,file_name);
    times(&time_count[2]);
    time_count_real[2] = clock();

    write_to_report_single(raport, "f.biblioteki", time_count[0], time_count_real[0], time_count[1], time_count_real[1]);
    write_to_report_single(raport, "f.systemowe", time_count[1], time_count_real[1], time_count[2], time_count_real[2]);

}
