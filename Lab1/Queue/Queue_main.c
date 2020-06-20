#include <stdio.h>
#include <stdlib.h>
#include "Queue_header.h"

int main(void)
{
	Q* Queue = CreateQueue();

	Enqueue(Queue, 1);
	Enqueue(Queue, 9);
	Enqueue(Queue, 9);
	Enqueue(Queue, 9);
	Enqueue(Queue, 1);
	Enqueue(Queue, 2);
	Enqueue(Queue, 0);
	Enqueue(Queue, 1);
	printf("\n");
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);
	Dequeue(Queue);

	isEmpty(Queue);
}