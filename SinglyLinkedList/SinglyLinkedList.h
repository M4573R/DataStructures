#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "ListNode.h"
#include "ListIterator.h"

using namespace std;

class SinglyLinkedList {
	public:
		SinglyLinkedList();
		// SinglyLinkedList(int * arr);
		SinglyLinkedList(const SinglyLinkedList& source);
		~SinglyLinkedList();
		SinglyLinkedList& operator=(const SinglyLinkedList& source);
		void insert_after(int prev, int v);
		void insert_at_head(int v);
		bool find(int v);
		void remove(int v);
		void print_list();
	private:
		ListNode * head;
		ListIterator * it;
		int size;
		ListNode * find(ListNode* & node, int v);
		friend class ListNode;
		friend class ListIterator;
};

SinglyLinkedList * reverse(SinglyLinkedList * input);

#endif
