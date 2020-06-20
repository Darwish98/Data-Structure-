typedef struct Node
{
	int data;				
	struct Node* next;		
}N;


void push(N** stack, int number);
int print_elemnt(N* stack);
void pop(N** stack);
int isEmpty(N* stack);