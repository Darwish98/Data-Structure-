#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Q1_Header.h"



N* CreateNode(int num)
{
	N* head = (N*)malloc(sizeof(N));
	if (head == NULL)
	{
		printf("failed to allocate memory");
		return NULL;
	}
	
	head->data = num;
	head->next = NULL;
	head->prev = NULL;

	return head;
}



L*CreateList()
{
	L* head1 =(L*)malloc(sizeof(L));
	if (head1 == NULL)
	{
		printf("failed to allocate memory");
		return NULL;
	}

	head1->key = NULL;
	return head1;

}

void isEmpty(L*list)
{
	if (list->key == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("list is not empty\n");
	}
}

int print_list(L* list)
{
	N* node = list->key;
	
	printf(" _____ _            _     _     _   \n");
	printf("|_   _| |          | |   (_)   | |  \n");
	printf("  | | | |__   ___  | |    _ ___| |_ \n");
	printf("  | | | '_   / _   | |   | / __| __|\n");
	printf("  | | | | | |  __/ | |___|  __ | |_ \n");
	printf("  | | |_| |_| ___| |_____|_|___/|__|\n");
	printf("  -----------------------------\n");
	printf("  |%d |",node->data);

	while (node->next!= NULL)
	{
		node = node->next;
		printf("|%d | ",node->data);
		
	}
	printf("\n  -----------------------------\n");

	return 0;
}

N* delete(L* list, N* node)
{
	if(list->key==NULL)
	{
		printf("The list is empty\n");
		return NULL;
	}
	if (node == list->key)
	{
		list->key = list->key->next;
	}
	if (node->next != NULL)
	{
		node->next->prev=node->prev;
	}
	if (node->prev != NULL)
	{
		node->prev->next = node->next;
	}
	return node;
	
}


void insert(L*list,N*node)
{
	if(list->key== NULL)
	{
		list->key = node;
	}
	else 
	{ 
		node->next = list->key;
		list->key = node;
		node->next->prev = node;
		
	}
}

N* search(L* list, int k)
{
	N* node = list->key;
	
	while (node!= NULL)
	{
		if (node->data == k)
		{
			return node;
			printf("Node is in the list and the adress is %p", node);//adress
			exit(1);
		}

		node=node->next;
	}
	printf("Node is not in the list\n");
	return NULL;
}



int maximum(L*list)
{

	N* current = list->key;
	int max = current->data;
	if (current== NULL)
	{
		printf("The list is empty\n");
	}
	while (current != NULL)
	{
		
		if (current->data >max)
		{
			max = current->data;
		}
		current= current->next;
	}
	return max;
	
}


int minimum(L* list)
{
	N* current = list->key;
	int min = current->data;
	if (current == NULL )
	{
		printf("The list is empty\n");
	}
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
		}
		current= current->next;
	}
	
	return min;
	
}

int* successor(L*list, N*node)
{
	L* min_list=CreateList();
	N* current2= list->key;
	int* minValue= (int*)malloc(sizeof(int));
	
	
	while (current2 != NULL)
	{
		if (current2->data > node->data)
		{
			
			insert(min_list, CreateNode(current2->data));
		}
		current2 = current2->next;
	}
	if (maximum(list) == node->data)
	{
		printf("  %d is the maximum and have no successor\n", node->data);
		return NULL;
	}

	if (min_list->key == NULL)
	{
		return NULL;
	}
	else
	{
		*minValue = minimum(min_list);
		printf("  The successor of %d is: %d\n", node->data, *minValue);

		return minValue;

	}

	
	
	
}

int* predecessor(L* list, N* node)
{
	L* max_list = CreateList();
	N* current = list->key;
	int* maxValue=(int*)malloc(sizeof(int));
	if (maxValue == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}

	while (current != NULL)
	{
		if (current->data < node->data)
		{
			insert(max_list, CreateNode(current->data));
		}
		current = current->next;
	}
	if (minimum(list) == node->data)
	{
		printf("  %d is the minimum and have no predecssor\n", node->data);
		return NULL;
	}

	if (max_list->key == NULL)
	{
		return NULL;
	}

	*maxValue = maximum(max_list);
	printf("  The predecessor of %d is: %d\n", node->data, *maxValue);

	return maxValue;

}
