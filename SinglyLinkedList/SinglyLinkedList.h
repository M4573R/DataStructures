#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "ListNode.h"
#include "ListIterator.h"

using namespace std;

friend ListNode;
friend ListIterator;

class SinglyLinkedList {
	public:
		SinglyLinkedList();
		// SinglyLinkedList(int * arr);
		SinglyLinkedList(const SinglyLinkedList& source);
		~SinglyLinkedList();
		SinglyLinkedList& operator=(const SinglyLinkedList& source);
		void insert_after(int v);
		ListIterator * find(int v);
		void remove(int v);
		string print_list();
	private:
		ListNode * head;
		ListIterator * it;
		int size;
};

SinglyLinkedList * reverse(SinglyLinkedList * input);

#endif
