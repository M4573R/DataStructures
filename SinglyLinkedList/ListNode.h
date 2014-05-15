#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

class ListNode {
	public:
		ListNode();
		ListNode(int v);
		~ListNode();
	private:
		int value;
		ListNode * next;
		friend class ListIterator;
		friend class SinglyLinkedList;
};

#endif
