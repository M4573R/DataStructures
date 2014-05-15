#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
	cout<<"HELLO";
	AVLTree * avl = new AVLTree();
	avl->insert(15);
	avl->insert(6);
	avl->insert(18);
	avl->insert(19);
	avl->insert(17);
	cout << (avl->find(4) ? "true" : "false") << endl;
	cout << (avl->find(19) ? "true" : "false") << endl;
	avl->print_tree();
	avl->remove(6);
	cout<<endl;
	avl->print_tree();


	return 0;
}
