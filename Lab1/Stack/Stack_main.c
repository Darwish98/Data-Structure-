#include <stdio.h>
#include <stdlib.h>
#include "Stack_header.h"

int main(void)
{
	struct Node* Stack= NULL;

	push(&Stack, 1);
	push(&Stack, 2);
	push(&Stack, 9);
	push(&Stack, 7);
	push(&Stack, 0);
	push(&Stack, 1);
	push(&Stack, 0);
	push(&Stack, 1);
	printf("\n");
	pop(&Stack);
	pop(&Stack);
	pop(&Stack);
	pop(&Stack);
	pop(&Stack);
	pop(&Stack);
	pop(&Stack);
	pop(&Stack);


}