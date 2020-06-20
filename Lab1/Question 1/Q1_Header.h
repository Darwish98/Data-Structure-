
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;

}N;
typedef struct List 
{
	struct Node*key;
}L;


void isEmpty(L* list);
L* CreateList();
N* CreateNode(int num);
void insert(L* list, N* node);
N* delete(L* list, N* node);
N* search(L* list,int k);
int print_list(L* list);
int maximum(L* list);
int minimum(L* list);
int* successor(L* list, N* node);
int* predecessor(L* list, N* node);