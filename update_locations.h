#pragma once
#include <stdio.h>
#include <stdlib.h>
int8_t* generate_random_list( int size, int bound);

int sum(int8_t* xs, int8_t* ys, int8_t* zs, int size);

void updatecoords(int8_t *xs, int8_t *ys, int8_t *zs, int8_t *vx, int8_t *vy, int8_t *vz);

int main(int argc, char *argv[]);

