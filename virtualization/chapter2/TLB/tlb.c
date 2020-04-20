#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
int PAGESIZE = 4096;
long gettimenow(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    //printf("the time is %d\n",tv->tv_sec * 1e6 + tv->tv_usec);
    return tv.tv_sec * 1e6 + tv.tv_usec;
}
int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "the number of arguments is wrong, its number is %d\n", argc);
        exit(1);
    }
    int jump = PAGESIZE / sizeof(int);
    int NUMPAGES = atoi(argv[1]);
    int TRIAL = atoi(argv[2]);
    //int *a = (int *)malloc(sizeof(int) * NUMPAGES * jump);
    int *a = (int *)calloc( NUMPAGES * jump,sizeof(int));

    long start, end = 0;
    int sum;
    for(int j=0; j<TRIAL; j++){
        if(j == 0){
            start = gettimenow();
        }
        for(int i=0; i< NUMPAGES * jump; i += jump){
            a[i] += 1;
        }
    }
    end = gettimenow();
    sum = end-start;
    //printf("the average time of per pagecost is %f microseconds\n", ((double)sum/TRIAL)/NUMPAGES);
    // easy to get the data
    printf("%f\n", ((double)sum/TRIAL)/NUMPAGES * 1000);

    return 0;
}