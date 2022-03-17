#include <stdio.h>
#include <stdlib.h>
#include "task1_lib.h"
#include "task1_sys.h"
#include <time.h>
#include <unistd.h>
#include <sys/times.h>


void write_to_report_single(FILE * raport, char* header,  struct tms time_count, clock_t time_count_real, struct tms time_count2, clock_t time_count_real2){
    fprintf(raport,"%s    %lf",header, (double) (time_count_real2 - time_count_real) / CLOCKS_PER_SEC );
    fprintf(raport,"            %lf",(double) (time_count2.tms_utime - time_count.tms_utime) / sysconf(_SC_CLK_TCK));
    fprintf(raport,"            %lf \n",(double) (time_count.tms_stime - time_count.tms_stime) / sysconf(_SC_CLK_TCK));
}

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

    struct tms time_count[5];
    clock_t time_count_real[5];
    FILE *raport;
    raport = fopen("pomiar_zad_1.txt","w");
    fprintf(raport,"%s","            REAL         USER         SYS\n");

    times(&time_count[0]);
    time_count_real[0] = clock();
    copy_from_file(first_file,second_file);
    times(&time_count[1]);
    time_count_real[1] = clock();
    copy_from_file_sys(first_file,second_file);
    times(&time_count[2]);
    time_count_real[2] = clock();

    write_to_report_single(raport, "f.biblioteki", time_count[0], time_count_real[0], time_count[1], time_count_real[1]);
    write_to_report_single(raport, "f.systemowe", time_count[1], time_count_real[1], time_count[2], time_count_real[2]);
}