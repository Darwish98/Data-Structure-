#include "Q1_header.h"


array* Createarray2(int*list,int size)
{
	int i;
	array* a = (array*)malloc(sizeof(array));
	if (a == NULL) return NULL;
	a->size = size;
	a->arr = (int*)malloc(sizeof(int) * size);
	if (a->arr == NULL) return NULL;

	for (i = 0; i < size; i++)
	{
		a->arr[i] = list[i];
	}
	

	return a;

}


array* Createarray(int size)
{
	int num,i;
	array* a = (array*)malloc(sizeof(array));
	if (a == NULL) return NULL;
	a->size = size;
	a->arr = (int*)malloc(sizeof(int) * size);
	if (a->arr == NULL) return NULL;
	printf("Enter %d elemnts:", size);

	for(i=0;i<size;i++)
	{
		scanf_s("%d",&num);
		a->arr[i] = num;
	}

	return a;
	
}




// time complexity O(n^2) 

array* insertionSort(array *ar)
{
	int i, j, x;

	for (i = 0; i < ar->size ; i++)
	{
		x = ar->arr[i];
		j = i - 1;
		while (j >= 0 && ar->arr[j] > x)
		{
			ar->arr[j + 1] = ar->arr[j];
			j = j - 1;

		}
		ar->arr[j + 1] = x;
	}
	
	return ar;
}

void printarray(array* arr)
{
	int j;
	printf("\nList after sorting:\n");
	printf("---------------------------------------------------\n");
	for (j = 0; j < arr->size; j++)
		printf("( %d )", arr->arr[j]);
		
	printf("\n\n\n");
}

// time complexity(n*log(n)) << n^2, much better than insertion sort
void MergeSort(array* ar,int FirstSub,int LastSub)
{
	if (FirstSub < LastSub) {
		int Middle;
		Middle = FirstSub + (LastSub-FirstSub)/2;
		MergeSort(ar, FirstSub, Middle);
		MergeSort(ar, Middle + 1, LastSub);
		Merge(ar, FirstSub, Middle, LastSub);

	}
}
void Merge(array* ar, int FirstSub, int middle, int LastSub)
{
	int i, j, k;
	int L1 = middle- FirstSub + 1;
	int L2 = LastSub - middle;
	

	int *Left = (int*)malloc(sizeof(int)*L1);
	int *Right = (int*)malloc(sizeof(int)*L2);

	if (Left == NULL || Right == NULL) return;

	for (i = 0; i < L1; i++) {
		Left[i] = ar->arr[FirstSub + i];
	}
	for (j = 0; j < L2; j++) {
		Right[j] = ar->arr[middle + 1 + j];
	}
	k = FirstSub;
	i = 0;
	j = 0;
	while (i < L1 && j < L2) {
		if (Left[i] <= Right[j]) 
		{
			ar->arr[k] = Left[i];
			i++;
		}
		else {
			ar->arr[k] = Right[j];
			j++;
		}
		k++;
	}
	while(i < L1) {
		ar->arr[k] = Left[i];
		i++;
		k++;
	}
	while(i < L2) {
		ar->arr[k] = Right[j];
		
		j++;
		k++;
	}
	free(Left);
	free(Right);
}


int* load_file(const char* fName)
{
	int input[MAX_NUM_ELEMENTS];
	int num_elements = 0;

	FILE* file = fopen(fName, "r");
  if ( file == NULL ) {
    printf("Error: file does not exist. Exiting...\n");
    exit(1);
  }
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		input[num_elements++] = atoi(line);
		//printf("%d", atoi(line));
	}
	fclose(file);
	
	int* data = (int*)malloc((num_elements+1)*sizeof(int));
	if (data == NULL) return NULL;
	for ( int i = 1 ; i <= num_elements ; i++ ) 
	{
		data[i] = input[i-1];
	}
	data[0] = num_elements;
	return data;
}

