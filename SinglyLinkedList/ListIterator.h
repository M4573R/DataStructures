#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "ListNode.h"

using namespace std;

class ListIterator {
	public:
		ListIterator();
		ListIterator(ListNode * curr);
		void move_forward();
	private:
		ListNode * current;
		friend class ListNode;
		friend class SinglyLinkedList;
};

#endif
