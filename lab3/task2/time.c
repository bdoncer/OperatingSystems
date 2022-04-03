#include <stdio.h>
#include <stdlib.h>
#include "task2_lib.h"
#include <time.h>
#include <unistd.h>
#include <sys/times.h>


void write_to_report_single(FILE * raport, struct tms time_count, clock_t time_count_real, struct tms time_count2, clock_t time_count_real2){
    fprintf(raport,"            %lf", (double) (time_count_real2 - time_count_real) / CLOCKS_PER_SEC );
    fprintf(raport,"            %lf",(double) (time_count2.tms_utime - time_count.tms_utime) / sysconf(_SC_CLK_TCK));
    fprintf(raport,"            %lf \n",(double) (time_count.tms_stime - time_count.tms_stime) / sysconf(_SC_CLK_TCK));
}

int main(int argc, char *argv[]) {

    FILE *raport;
    struct tms time_count[10];
    clock_t time_count_real[10];

    times(&time_count[0]);
    time_count_real[0] = clock();
    count_integral(0.001,1000,1);
    times(&time_count[1]);
    time_count_real[1] = clock();

    times(&time_count[1]);
    time_count_real[1] = clock();
    count_integral(0.00001,10000,01);
    times(&time_count[2]);
    time_count_real[2] = clock();

    times(&time_count[2]);
    time_count_real[2] = clock();
    count_integral(0.00000001,10000,1);
    times(&time_count[3]);
    time_count_real[3] = clock();

    times(&time_count[3]);
    time_count_real[3] = clock();
    count_integral(0.0000000000001,1000,1);
    times(&time_count[4]);
    time_count_real[4] = clock();

    raport = fopen("pomiar_zad_2.txt","w");
    fprintf(raport,"%s","                                                                          REAL                USER                 SYS\n");
    fprintf(raport,"szerokosc prostokata: 0.001 ilosc procesow: 1000");
    write_to_report_single(raport, time_count[0], time_count_real[0], time_count[1], time_count_real[1]);
    fprintf(raport,"szerokosc prostokata: 0.00001 ilosc procesow: 10000");
    write_to_report_single(raport, time_count[1], time_count_real[1], time_count[2], time_count_real[2]);
    fprintf(raport,"szerokosc prostokata: 0.00000001 ilosc procesow: 10000");
    write_to_report_single(raport, time_count[2], time_count_real[2], time_count[3], time_count_real[3]);
    fprintf(raport,"szerokosc prostokata: 0.0000000000001 ilosc procesow: 1000");
    write_to_report_single(raport, time_count[3], time_count_real[3], time_count[4], time_count_real[4]);

}