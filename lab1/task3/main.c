#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include "task3.h"

char first_file[100];

void add_and_delete(int nr);
void run_tests();

int main(int n, char *commands[]) {
    int i = 1;
    while(i<n){
        if (strcmp (commands[i],"count_text") == 0){
            i++;
            for(int j = 0;j< 100;j++){
                first_file[j] = commands[i][j];
            }
            break;
        }
        i++;
    }

    i = 1;
    while(i<n){
        if (i<n && strcmp (commands[i],"make_array") == 0){
            i++;
            if (i<n && atoi(commands[i]) != 0){
                make_array(atoi(commands[i]));
            }
            else{
                printf("you have to enter a number after make_array");
                exit(1);
            }

        }
        if (i<n && strcmp (commands[i],"count_text") == 0){
            i++;
            int start = i;
            while (i<n && strcmp (commands[i],"make_array") != 0 && strcmp (commands[i],"count_text") != 0 && strcmp (commands[i],"write_from_file") != 0 && strcmp (commands[i],"delete_block") != 0){
                i++;
            }
            int end = i-1;
            int k = end-start+1;
            char files[k][100];
            for(int j = 0;j<k;j++){
                for(int l=0;l<100;l++){
                    files[j][l] = commands[start+j][l];
                }

            }
            count_text(files,k);
            i--;
        }
        if (i<n && strcmp (commands[i],"write_from_file") == 0){
            write_from_file();
        }
        if (i<n && strcmp (commands[i],"delete_block") == 0){
            i++;
            if (i<n && atoi(commands[i]) != 0){
                delete_block(atoi(commands[i]));;
            }
            else{
                printf("you have to enter a number after delete_block");
                exit(1);
            }
        }
        if (i<n && strcmp (commands[i],"add_and_delete") == 0){
            i++;
            if (i<n && atoi(commands[i]) != 0){
                int nr = atoi(commands[i]);
                add_and_delete(nr);
            }
            else{
                printf("you have to enter a number after delete_block");
                exit(1);
            }

        }
        i++;
    }
    if(n==1){
        run_tests();
    }

}

void add_and_delete(int nr) {
    int indexes[nr];
    for(int p = 0;p<10;p++){
        for(int k = 0;k<nr;k++){
            count_text_one_file(first_file);
            indexes[k] = write_from_file();
        }
        for(int k = 0;k<nr;k++){
            delete_block(indexes[k]);
        }
    }
}

void write_to_report_single(FILE * raport, char* header,  struct tms time_count, clock_t time_count_real, struct tms time_count2, clock_t time_count_real2){
    fprintf(raport,"%s    %lf",header, (double) (time_count_real2 - time_count_real) / CLOCKS_PER_SEC );
    fprintf(raport,"            %lf",(double) (time_count2.tms_utime - time_count.tms_utime) / sysconf(_SC_CLK_TCK));
    fprintf(raport,"            %lf \n",(double) (time_count.tms_stime - time_count.tms_stime) / sysconf(_SC_CLK_TCK));
    printf("%s    %lf",header, (double) (time_count_real2 - time_count_real) / CLOCKS_PER_SEC );
    printf("            %lf",(double) (time_count2.tms_utime - time_count.tms_utime) / sysconf(_SC_CLK_TCK));
    printf("            %lf \n",(double) (time_count2.tms_stime - time_count.tms_stime) / sysconf(_SC_CLK_TCK));
}
void write_to_raport(FILE * raport,struct tms time_count[5],clock_t time_count_real[5]){

    write_to_report_single(raport, "ALLOCATE ", time_count[0], time_count_real[0], time_count[1], time_count_real[1]);
    write_to_report_single(raport, "COUNT    ", time_count[1], time_count_real[1], time_count[2], time_count_real[2]);
    write_to_report_single(raport, "WRITE    ", time_count[2], time_count_real[2], time_count[3], time_count_real[3]);
    write_to_report_single(raport, "ADDANDDEL", time_count[3], time_count_real[3], time_count[4], time_count_real[4]);

}

void run_tests(){
    struct tms time_count[5];
    clock_t time_count_real[5];
    FILE *raport;
    raport = fopen("raport2.txt","w");
    fprintf(raport,"%s","            REAL         USER         SYS\n");
    printf("%s","            REAL         USER         SYS\n");

    //test for small file
    fprintf(raport,"%s","\nsmall file\n");
    printf("%s","\nsmall file\n");
    times(&time_count[0]);
    time_count_real[0] = clock();
    make_array(100);
    times(&time_count[1]);
    time_count_real[1] = clock();
    count_text_one_file("small");
    times(&time_count[2]);
    time_count_real[2] = clock();
    write_from_file();
    times(&time_count[3]);
    time_count_real[3] = clock();
    strncpy(first_file, "small", 100);
    add_and_delete(10);
    times(&time_count[4]);
    time_count_real[4] = clock();
    write_to_raport(raport,time_count,time_count_real);

    //test for medium file
    fprintf(raport,"%s","\nmedium file\n");
    printf("%s","\nmedium file\n");
    times(&time_count[0]);
    time_count_real[0] = clock();
    make_array(100);
    times(&time_count[1]);
    time_count_real[1] = clock();
    count_text_one_file("medium");
    times(&time_count[2]);
    time_count_real[2] = clock();
    write_from_file();
    times(&time_count[3]);
    time_count_real[3] = clock();
    strncpy(first_file, "medium", 100);
    add_and_delete(10);
    times(&time_count[4]);
    time_count_real[4] = clock();
    write_to_raport(raport,time_count,time_count_real);

    //test for big file
    fprintf(raport,"%s","\nbig file\n");
    printf("%s","\nbig file\n");
    times(&time_count[0]);
    time_count_real[0] = clock();
    make_array(100);
    times(&time_count[1]);
    time_count_real[1] = clock();
    count_text_one_file("big");
    times(&time_count[2]);
    time_count_real[2] = clock();
    write_from_file();
    times(&time_count[3]);
    time_count_real[3] = clock();
    strncpy(first_file, "big", 100);
    add_and_delete(10);
    times(&time_count[4]);
    time_count_real[4] = clock();
    write_to_raport(raport,time_count,time_count_real);


    //test for 3 files
    fprintf(raport,"%s","\n3 files\n");
    printf("%s","\n3 files\n");
    times(&time_count[0]);
    time_count_real[0] = clock();
    make_array(100);
    times(&time_count[1]);
    time_count_real[1] = clock();
    char bla[][100] = { "test1","test2","small"
    };
    count_text(bla,3);
    times(&time_count[2]);
    time_count_real[2] = clock();
    write_from_file();
    times(&time_count[3]);
    time_count_real[3] = clock();
    strncpy(first_file, "small", 100);
    add_and_delete(10);
    times(&time_count[4]);
    time_count_real[4] = clock();
    write_to_raport(raport,time_count,time_count_real);

    //test for 6 files
    fprintf(raport,"%s","\n6 files\n");
    printf("%s","\n6 files\n");
    times(&time_count[0]);
    time_count_real[0] = clock();
    make_array(100);
    times(&time_count[1]);
    time_count_real[1] = clock();
    char blabla[][100] = { "test1","test2","test3","small","medium","test1"
    };
    count_text(blabla,6);
    times(&time_count[2]);
    time_count_real[2] = clock();
    write_from_file();
    times(&time_count[3]);
    time_count_real[3] = clock();
    strncpy(first_file, "medium", 100);
    add_and_delete(10);
    times(&time_count[4]);
    time_count_real[4] = clock();
    write_to_raport(raport,time_count,time_count_real);

    //test for 10 files
    fprintf(raport,"%s","\n10 files\n");
    printf("%s","\n10 files\n");
    times(&time_count[0]);
    time_count_real[0] = clock();
    make_array(100);
    times(&time_count[1]);
    time_count_real[1] = clock();
    char blablabla[][100] = { "test1","test2","test3","small","medium","test1","medium","big","test3","medium"
    };
    count_text(blablabla,10);
    times(&time_count[2]);
    time_count_real[2] = clock();
    write_from_file();
    times(&time_count[3]);
    time_count_real[3] = clock();
    strncpy(first_file, "big", 100);
    add_and_delete(10);
    times(&time_count[4]);
    time_count_real[4] = clock();
    write_to_raport(raport,time_count,time_count_real);

    fclose(raport);

}
