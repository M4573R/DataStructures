#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
	head = new ListNode;
	it = new ListIterator(head);
}
/* TODO: Finish these methods */
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

void SinglyLinkedList::insert_after(int prev, int v) {
	it->current = find(head,prev);
	if (it->current == NULL) {
		insert_at_head(v);
		return;
	}
	ListNode * n = new ListNode(v);
	if (it->current->next != NULL) {
		n->next = it->current->next;
	}
	it->current->next = n;
	size++;
}

void SinglyLinkedList::insert_at_head(int v) {
	it->current = head;
	ListNode * n = new ListNode(v);
	if (it->current->next != NULL) {
		n->next = it->current->next;
	}
	it->current->next = n;
	size++;	
}

bool SinglyLinkedList::find(int v) {
	return (find(head, v) != NULL ? true : false);
}

ListNode * SinglyLinkedList::find(ListNode*& node, int v) {
	it->current = node;
	while (it->current != NULL) {
		if (it->current->value == v) {
			return it->current;
		}
		it->move_forward();
	}
	return NULL;
}

void SinglyLinkedList::remove(int v) {
	int i = 0;
	bool found = false;
	it->current = head;
	while (it->current != NULL) {
		if (it->current->value == v) {
			found = true;
			break;
		}
		it->move_forward();
		i++;
	}
	if (found) {
		ListIterator * tmp = new ListIterator(head);
		for (int j = 0; j < i-1; j++) {
			tmp->move_forward();
		}
		tmp->current->next = it->current->next;
		it->current->next = NULL;
		delete it->current;
		size--;
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