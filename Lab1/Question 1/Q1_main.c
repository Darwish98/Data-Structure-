#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Q1_Header.h"



int main()
{
	

	while (1)
	{
		int option;
		printf("\n  1.Info about list 1\n  2.Info about list 2\n  choose an option: ");
		scanf("%d", &option);


		
		if (option == 1)
		{
			L* list1 = CreateList();
			N* node1 = CreateNode(3);
			N* node2 = CreateNode(1);
			N* node3 = CreateNode(5);
			N* node4 = CreateNode(10);
			N* node5 = CreateNode(8);
			N* node6 = CreateNode(7);
			insert(list1, node1);
			insert(list1, node2);
			insert(list1, node3);
			insert(list1, node4);
			insert(list1, node5);
			insert(list1, node6);
			print_list(list1);
			printf("  Maximium of list is:%d\n", maximum(list1));
			printf("  Minimum of list is:%d\n", minimum(list1));
			successor(list1, node3);
			predecessor(list1, node3);
		}

		
		if (option == 2)
		{
			L* list2 = CreateList();
			N* node7 = CreateNode(5);
			N* node8 = CreateNode(2);
			N* node9 = CreateNode(9);
			N* node10 = CreateNode(6);
			N* node11 = CreateNode(1);
			N* node12 = CreateNode(2);
			insert(list2, node7);
			insert(list2, node8);
			insert(list2, node9);
			insert(list2, node10);
			insert(list2, node11);
			insert(list2, node12);
			print_list(list2);
			printf("  Maximum of list is:%d\n", maximum(list2));
			printf("  Minimum of list is:%d\n", minimum(list2));
			successor(list2, node9);
			predecessor(list2, node9);
		}
		
	}

}

	
	
	


