#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main() {
	BinarySearchTree * bst = new BinarySearchTree();
	// int arr[] = {5,6,2,7,1,8,3,5,4,6,7,3};
	// BinarySearchTree * bst2 = new BinarySearchTree(arr);
	bst2->print_tree();
	bst->insert(15);
	bst->insert(6);
	bst->insert(18);
	bst->insert(19);
	bst->insert(17);
	cout << (bst->find(4) ? "true" : "false") << endl;
	cout << (bst->find(19) ? "true" : "false") << endl;
	bst->print_tree();
	bst->remove(6);
	cout<<endl;
	bst->print_tree();


	return 0;
}
