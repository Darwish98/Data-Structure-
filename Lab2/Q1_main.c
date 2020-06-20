
#include "Q1_header.h"


int main()
{
	while (1)
	{
		int option;
		printf("\n-------------------------------\n1.run tests\n2.test with you own array\nchoose and option:\n\n");
		scanf_s("%d", &option);
	

		if (option == 1)
		{
			
			const char* fName = "sorting_problems/test-100000-5-problem";
			int* a = load_file(fName);
			int size = a[0];

			for (int i = 1; i <= size; i++) // note this loops from 1 <= i <= size
			{
				printf("%d\n", a[i]);
			}
			int optionnn;
			printf("\n\nSort the array using:\n--------------------------------\n1.Insertion Sort\n2.Megre Sort\n---------------------------------\nchoose an option:");
			scanf_s("%d", &optionnn);

			array* list = Createarray2(a, size);
			if (optionnn == 1)
			{
				insertionSort(list); //runtime test-100000-5-problem is 14.34 seconds
				printarray(list);
			}
		
			if (optionnn == 2)
			{
				MergeSort(list, 0, size - 1); //runtime test-100000-5-problem is 6.41 seconds
				printarray(list);  

			}
		
		}


		if (option == 2)
		{
			int num, optionn;
			printf("\n\nEnter amount of numbers to be sorted:");
			scanf_s("%d", &num);
			array* arr = Createarray(num);
			printf("\n\nSort the array using:\n--------------------------------\n1.Insertion Sort\n2.Megre Sort\n---------------------------------\nchoose an option:");
			scanf_s("%d", &optionn);

			if (optionn == 1)
			{
				insertionSort(arr);
				printarray(arr);
			}
			if (optionn == 2)
			{
				MergeSort(arr, 0, arr->size - 1);
				printarray(arr);
			}


		}
	}

}

/*

 • The input array is sorted in descending order;
   answer: Merge sort 


• The input array is sorted in ascending order;
  answer: Insertion sort prformance very well when the array is alredy 
  in sorted order which is also the best case of Insertion sort with time-
  complexity O(n)


• All elements in the array are the same.
  answer: An array where all the elemnts are the same are already sorted, and the best alogrithm for sorted arrays
  is Insetion sort with time-complexity O(n)


• There are both positive and negative numbers in the array
  answer:It dosent matter if the array has negativ or/and positive numbers and the alogrithm will behave the same, 
  thefore we can choose the alogrithm with best average time complexity which is merge sort becuase in all cases
  the time complexity is O(nlogn). Eventhough Quick sort is almost as good as merge sort but it has a worst case where
  time complexity is O(n^2) <<<< O(nlogn). Therfore MegreSort is the best alogrithm in most common situations. 




*/
















