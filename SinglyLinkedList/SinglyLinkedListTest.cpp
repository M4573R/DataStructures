#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
	SinglyLinkedList * list = new SinglyLinkedList();

	list->insert_after(3,3);
	list->insert_after(3,4);
	list->insert_after(4,5);
	list->print_list();
	cout << ( list->find(4) ? "TRUE\n" : "FALSE\n" );
	list->remove(5);
	list->print_list();

	return 0;
}