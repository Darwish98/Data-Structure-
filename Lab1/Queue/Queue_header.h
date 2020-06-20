typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}N;

typedef struct Queue
{
	struct Node* key;

}Q;


void Enqueue(Q* queue, int number);
int print_elemnt(N* queue);
void Dequeue(Q* queue);
int isEmpty(Q* queue);
Q* CreateQueue();