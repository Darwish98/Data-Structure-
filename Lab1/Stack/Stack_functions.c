#include <stdio.h>
#include <stdlib.h>
#include "Stack_header.h"
void push(N** stack, int number)
{
	N* current = NULL;
	current = (N*)malloc(sizeof(N));
	if (current ==NULL)
	{
		printf("\nmemory allocation failed");
		exit(1);
	}
	printf("| pushing %d |\n", number);
	printf("--------------\n");
	current->data = number;
	current->next = *stack;
	*stack = current;
}


int print_elemnt(N* stack)
{
	if (stack != NULL){
		return stack->data;
	}
	else {
		exit(1);
	}
}

int isEmpty(N* stack)
{
	if (stack == NULL)
		printf("Stack is empty");
	else
		printf("Stack is not empty");
	return 0;

}

void pop(N** stack)
{
	
	if (*stack == NULL)
	{
		printf("\nstack is empty");
		exit(1);
	}
	printf("| poping %d  |\n", print_elemnt(*stack));
	printf("--------------\n");
	*stack = (*stack)->next;

}