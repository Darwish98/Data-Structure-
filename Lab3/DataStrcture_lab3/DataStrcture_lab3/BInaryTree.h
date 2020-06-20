#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



typedef struct Node {
	int data;
	struct Node* right;
	struct Node* left;
}N;
typedef struct BinaryTree
{
	struct Node* root;

}BT;


#ifndef LOAD_FILE_H
#define LOAD_FILE

#define MAX_NUM_ELEMENTS		100000

int* load_file(const char* fName);

#endif


void Successor(N* root,int key);//the successor
void Predecessor(N* root, int key);//the predecessor
N* maxi(N* root);//the maximum node in the BST
N* mini(N* root);//the minimum node in the BST
void isEmpty(BT* list);//check if the BST is empty
BT* CreateBinaryTree();//Creates an empty binary tree 
N* CreateNode(int num);// Creates a node with a given value

void insert(BT* list, N* node);//insert a given node in a right position
N* delete(N* list,int node);//delete a given node from tree
void search(N* root, int key);//search for a given node in the tree
void Inorder_print_list(N* root);//print inorder the keys/nodes
int size_tree(N* root);//calculates the number of elements in the tree(size of tree)
int depth(N* root);//counting the  depth