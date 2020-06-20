#include "BinaryTree.H"





N* CreateNode(int num)
{
	N* head = (N*)malloc(sizeof(N));
	if (head == NULL)
	{
		printf("failed to allocate memory");
		return NULL;
	}

	head->data = num;
	head->left = NULL;
	head->right = NULL;

	return head;
}



BT* CreateBinaryTree()
{
	BT* head1 = (BT*)malloc(sizeof(BT));
	if (head1 == NULL)
	{
		printf("failed to allocate memory");
		return NULL;
	}

	head1->root = NULL;
	
	return head1;

}

 
void insert(BT* list, N*node)
{
	
	if (list->root == NULL)
	{
		list->root = node;
	}

	else
	{
		N* current = list->root;
		while(current->data > node->data && current->left!=NULL)
		{
			current = current->left;
			while (current->data < node->data && current->right != NULL)
			{
				current = current->right;

			}

		}
		
		while (current->data < node->data && current->right!=NULL )
		{
			current = current->right;
			while (current->data > node->data&& current->left != NULL)
			{
				current = current->left;

			}

		}
		if (current->data < node->data)
		{
			current->right = node;
		}
		if (current->data > node->data)
		{
			current->left = node;
		}	
	}
}

N* delete(N* root, int node)
{
	if (root == NULL)
	{
		printf("The list is empty\n");
		return NULL;
	}

	if (node < root->data)
	{     
		root->left = delete(root->left, node);
	}
	else if (node > root->data) {

		root->right= delete(root->right, node);
	}
	else {
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->left == NULL || root->right == NULL)
		{
			N* current;
			if (root->left == NULL)
			{
				current = root->right;
			}
			else
			{
				current = root->left;
			}
			free(root);
			return current;
		}
		else 
		{
			N* curr = mini(root->right);
			root->data = curr->data;
			root->right = delete(root->right, curr->data);
		}
	}
	return root;
}


void isEmpty(BT* list)
{
	if (list->root == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("list is not empty\n");
	}
}





N* mini(N* root)
{
	N* current = root;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

N*maxi(N* root)
{

	N* current = root;
	while (current->right != NULL)
	{
		current = current->right;
	}
	return current;
}



void search(N* root, int key)
{
	N* current = root;
	while (current != NULL && key != current->data)
	{
		if (key < current->data)
		{
			current = current->left;
		}
		else
			current = current->right;
	}
	if (current == NULL)
		printf("Node %d is not in the list\n", key);
	else
		printf("Node %d is in the list", key);
}



void Successor(N* root, int key)
{
	N* current = root;
	N* successor = NULL;
	
	while (current->data != key)
	{
		if (current->data > key)
		{
			successor = current;
			current = current->left;
		}
		else
			current = current->right;
	}
	if (current!=NULL && current->right) {
		successor = mini(current->right);
	}
	if (successor == NULL)
	{
		printf("\n%d has no Successor", key);
	}
	else
		printf("\n%d Successor is %d\n", key, successor->data);

}

void Predecessor(N* root, int key)
{
	N* current = root;
	N* predecessor = NULL;

	while (current->data !=key)
	{
		if (current->data < key)
		{
			predecessor = current;
			current = current->right;
		}
		else
			current = current->left;
	}
	if (current != NULL && current->left != NULL) {
		predecessor = maxi(current->left);
	}
	if (predecessor == NULL)
	{
		printf("\n%d has no predecessor\n", key);
	}
	else
		printf("%d predecessor is %d\n", key, predecessor->data);
}


void Inorder_print_list(N* root)
{
	N* current = root;
	if (current == NULL)

		return;

	Inorder_print_list(current->left);
	printf("%d ", current->data);
	Inorder_print_list(current->right);
}


int size_tree(N* root)
{
	N* current = root;
	if (current == NULL)

		return 0;

	else
		return(size_tree(current->left) + 1 + size_tree(current->right));
}


int depth(N* root)
{
	N* current = root;
	if (current == NULL)
		return 0;
	if (depth(root->left) > depth(root->right))
		return 1 + depth(root->left);
	else
		return 1 + depth(root->right);

}


int* load_file(const char* fName)
{
	int input[MAX_NUM_ELEMENTS];
	int num_elements = 0;
	

	//fopen lead to an error and fopen_s was recommended to use instead
	FILE* file;
	fopen_s(&file,fName, "r");
	if (file == NULL) {
		printf("Error: file does not exist. Exiting...\n");
		exit(1);
	}
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		input[num_elements++] = atoi(line);
		//printf("%d", atoi(line));
	}
	fclose(file);

	int* data = (int*)malloc((num_elements + 1) * sizeof(int));
	if (data == NULL) return NULL;
	for (int i = 1; i <= num_elements; i++)
	{
		data[i] = input[i - 1];
	}
	data[0] = num_elements;
	return data;
}
