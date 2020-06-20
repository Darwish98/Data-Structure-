#include "BinaryTree.H"

int main()
{
	const char* fName = "sorting_problems/test-10-1-problem";
	int* a = load_file(fName);
	int size = a[0];
	int i;
	BT* list = CreateBinaryTree();
	insert(list, CreateNode(a[1]));
	N* root = list->root;
	for (i = 2; i <= size; i++)
	{
		insert(list, CreateNode(a[i]));
		
	}
	Inorder_print_list(root);
	delete(root, 72); printf("\nDeleting %d..\n", 72);
	Inorder_print_list(root);
	Successor(root, 79);
	Predecessor(root, 73);
	printf("Minimum is %d\n", mini(root)->data);
	printf("Maximum is %d\n", maxi(root)->data);
	printf("Size of the tree is %d\n", size_tree(root));
	printf("depth of the tree is %d\n", depth(root));
	







	/*L* list = CreateBinaryTree();
	N* node1 = CreateNode(10);
	N* node2= CreateNode(5);
	N* node3= CreateNode(1);
	N* node4= CreateNode(50);
	N* node5= CreateNode(60);
	N* node6 = CreateNode(40);
	N* node7 = CreateNode(55);
	N* node8 = CreateNode(20);
	N* node9 = CreateNode(15);
	insert(list, node1);
	insert(list, node2);
	insert(list, node3);
	insert(list, node4);
	insert(list, node5);
	insert(list, node6);
	insert(list, node7);
	insert(list, node8);
	insert(list, node9);
	printf("Minimum is %d\n", mini(node1)->data);
	printf("Maximum is %d\n", maxi(node1)->data);
	Successor(node1, 40);
	Predecessor(node1, 40);
	search(node1, 100);
	Inorder_print_list(node1);
	printf("Size of the tree is %d\n",size_tree(node1));
	printf("depth of the tree is %d\n",depth(node1));
	*/
}