#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList * list = new SinglyLinkedList();

	list->insert_after(3);
	list->insert_after(4);
	list->insert_after(5);
	list->print_list();
	cout << ( list->find(4) ? "TRUE" : "FALSE" );
	list->remove(3);
	list->print_list();

	return 0;
}