#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "ListNode.h"

using namespace std;

class ListIterator {
	public:
		ListIterator();
		ListIterator(ListNode * curr);
		ListNode * get_current();
		void set_current(ListNode * n);
		void move_forward();
	private:
		ListNode * current;
};

#endif
