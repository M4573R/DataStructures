#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
	head = new ListNode();
	it = new ListIterator(head);
}

// SinglyLinkedListList::SinglyLinkedList(int * arr) {
// 	head = new ListNode;

// }

// SinglyLinkedList::SinglyLinkedListList(const SinglyLinkedListList& source) {
//     head=new ListNode;
//     tail=new ListNode;
//     head->next=tail;
//     tail->previous=head;
//     count=0;
//     ListItr iter(source.head->next);
//     while (!iter.isPastEnd()) {       // deep copy of the list
//         insertAtTail(iter.retrieve());
//         iter.moveForward();
//     }
// }

// SinglyLinkedList& SinglyLinkedList::operator=(const List& source) {
//    if (this == &source)
//         return *this;
//     else {
        // makeEmpty();
        // ListItr iter(source.head->next);
        // while (!iter.isPastEnd()) {
            // insertAtTail(iter.retrieve());
            // iter.moveForward();
//         }
//     }
//     return *this;
// }

SinglyLinkedList::~SinglyLinkedList() {
	delete head;
}

void SinglyLinkedList::insert_after(int v) {
	ListNode * n = new ListNode(v);
	if (it->current->next != NULL) {
		n->next = it->current->next;
	}
	it->current->next = n;
	size++;
}

ListIterator * SinglyLinkedList::find(int v) {
	it->current = head;
	while (it->current != NULL) {
		if (it->current->value == v) {
			return it;
		}
		it->move_forward();
	}
	return NULL;
}

void SinglyLinkedList::remove(int v) {
	int i = 0;
	it = find(v);
	while (it->current != NULL) {
		if (it->current->value == v) {
			ListIterator * tmp = new ListIterator();
			for (int j = 0; j < i; i++) {
				tmp->move_forward();
			}
			tmp->current->next = it->current->next;
			delete tmp;
			delete it->current;
			it->current = head;
			size--;
		}
		it->move_forward();
		i++;
	}
}

void SinglyLinkedList::print_list() {
	it->current = head;
	cout << "[";
	while (it->current != NULL) {
		cout << std::to_string(it->current->value);
		if (it->current->next != NULL) {
			cout << " -> ";
		}
		it->move_forward();
	}
	cout << "]\n";
}

SinglyLinkedList * reverse(SinglyLinkedList * input) {
	return NULL;
}