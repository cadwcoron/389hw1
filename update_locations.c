#include "update_locations.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Author: Caden Corontzos
// CSCI 389 - Spring 2022
// The script takes as input the size of the number of objects and the number of turns


double* generate_random_list( int size, int bound){
    double rand_list[size];
    for(int i = 0 ; i< size; i++){
        rand_list[i] = (double) ((rand()%(2*bound)) - bound);
        // printf("here: %f", rand_list[i]);
    }
    double* p;
    p = rand_list;
    return p;

}

int sum(double* xs, double* ys, double* zs, int size){
    int res =0;
    for(int i = 0; i< size; i++){
        res+=(xs[i]+ ys[i]+ zs[i]);
        
    }
    // printf("here: %i", res);
    return res;
}



void updatecoords(double *xs, double *ys, double *zs, double *vx, double *vy, double *vz){
    for(int i =0; i < (int) sizeof xs; i++){
        xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
    }
    return;
}

int main(int argc, char *argv[]){
    if(argc!=3){
        printf("Please supply arguments. I.e \n ./update_locations <num objs> <turns>\n");
        return 1;
    } 

    // produce n random numbers and sum them
    int numObjs = atoi(argv[1]);
    srand(numObjs);
    int numIterations = atoi(argv[2]);
    printf("Size: %i\n", numObjs);
    printf("Moves: %i\n" , numIterations);
    double* xs = generate_random_list(numObjs, 1000);
    double* ys = generate_random_list(numObjs, 1000);
    double* zs = generate_random_list(numObjs, 1000);
    double* vx = generate_random_list(numObjs, 1);
    double* vy = generate_random_list(numObjs, 1);
    double* vz = generate_random_list(numObjs, 1);
    struct timespec start, end;
    clock_gettime (CLOCK_MONOTONIC, &start);
    for(int i =0; i< numIterations; i++){
        updatecoords(xs,ys,zs,vx,vy,vz);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time = (end.tv_nsec - start.tv_nsec);
    printf("Time: %f\n",time);
    printf("Mean time per coordinate: %f\n", time*.001/ (numObjs*numIterations));
    int checksum = sum(xs,ys,zs,numObjs);
    printf("Final checksum is: %i\n", checksum);

    return 0;
}

