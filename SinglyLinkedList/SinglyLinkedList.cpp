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
	it->set_current(head);
	ListIterator * tmp = new ListIterator(head);
	while (it->get_current() != NULL) {
		delete tmp->get_current();
		it->move_forward();
		tmp = it;
	}
	delete tmp;
	delete head;
	delete it;
}

void SinglyLinkedList::insert_after(int v) {
	ListNode * n = new ListNode(v);
	if (it->get_current()->get_next() != NULL) {
		n->set_next(it->get_current()->get_next());
	}
	it->get_current()->set_next(n);
	size++;
}

ListIterator * SinglyLinkedList::find(int v) {
	it->set_current(head);
	while (it->get_current() != NULL) {
		if (it->get_current()->get_value() == v) {
			return it;
		}
		it->move_forward();
	}
	return NULL;
}

void SinglyLinkedList::remove(int v) {
	int i = 0;
	it = find(v);
	while (it->get_current() != NULL) {
		if (it->get_current()->get_value() == v) {
			ListIterator * tmp = new ListIterator();
			for (int j = 0; j < i; i++) {
				tmp->move_forward();
			}
			tmp->get_current()->set_next(it->get_current()->get_next());
			delete tmp;
			delete it->get_current();
			it->set_current(head);
			size--;
		}
		it->move_forward();
		i++;
	}
}

string SinglyLinkedList::print_list() {
	string list = "[ ";
	while (it->get_current() != NULL) {
		list += to_string(it->get_current()->get_value()) + " -> ";
	}
	list += " ]\n";
	return list;
}

SinglyLinkedList * reverse(SinglyLinkedList * input) {
	return NULL;
}