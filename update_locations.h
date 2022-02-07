#pragma once
#include <stdio.h>
#include <stdlib.h>
double* generate_random_list( int size, int bound);

int sum(double* xs, double* ys, double* zs, int size);

void updatecoords(double *xs, double *ys, double *zs, double *vx, double *vy, double *vz);

int main(int argc, char *argv[]);

