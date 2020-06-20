#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


typedef struct array {
	int* arr;
	int  size;
}array;

#ifndef LOAD_FILE_H
#define LOAD_FILE

#define MAX_NUM_ELEMENTS		100000

int* load_file(const char* fName);

#endif

array* Createarray2(int* list, int size);
array* Createarray(int size);
array* insertionSort(array*ar);
void MergeSort(array* ar, int FirstSub, int Lastsub);
void Merge(array* ar, int FirstSub, int SecondSub, int LastSub);
void printarray(array* arr);
int* load_file(const char* fName);