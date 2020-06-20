#include <stdio.h>
#include <stdlib.h>
#include "Queue_header.h"
Q* CreateQueue()
{
	Q* head1 = (Q*)malloc(sizeof(Q));
	if (head1 == NULL)
	{
		printf("failed to allocate memory");
		return NULL;
	}

	head1->key = NULL;
	return head1;

}


void Enqueue(Q* queue, int number)
{
	N* node =(N*)malloc(sizeof(N));
	node->data = number;
	node->next = NULL;
	node->prev = NULL;
	if (node == NULL)
	{
		printf("\nmemory allocation failed");
		exit(1);
	}
	if (queue->key == NULL)
	{
		queue->key = node;
	}
	else 
	{
		node->next = queue->key;
		queue->key = node;
		node->next->prev= node;

	}

	printf("| Enqueuing %d |\n", number);
	printf("--------------\n");
	
	
}


int print_elemnt(N* queue)
{
	if (queue != NULL) {
		return queue->data;
	}
	else {
		exit(1);
	}
}

int isEmpty(Q* queue)
{

	if (queue->key == NULL)
		printf("Queue is empty");
	else
		printf("Queue is not empty");
	return 0;
}

void Dequeue(Q*queue)
{
	N* current = queue->key;
	
	if (current == NULL)
	{
		printf("\nQueue is empty");
		exit(1);
	}
	else 
	{
		while (current->next!= NULL)
		{
			current = current->next;
		}
		if (current->next == NULL && current!= queue->key)
		{
	
			current->prev->next = NULL;
			current->prev = NULL;
		}

		printf("| Dequeuing %d  |\n", print_elemnt(current));
		printf("--------------\n");
		if (current == queue->key)
		{
			queue->key = NULL;
			
		}
		

		
		
		
	}


}
