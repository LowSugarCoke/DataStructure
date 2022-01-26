#ifndef _BLOOM_FILTER_H
#define _BLOOM_FILTER_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

int h1(char* s, int arr_size);
int h2(char* s, int arr_size);
int h3(char* s, int arr_size);
int h4(char* s, int arr_size);


int lookup(int* bitarray, int arr_size, char* s);
void insert(int* bitarray, int arr_size, char* s);

#endif
