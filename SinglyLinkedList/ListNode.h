#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

class ListNode {
	public:
		ListNode();
		ListNode(int v);
		int get_value();
		ListNode * get_next();
		void set_value(int v);
		void set_next(ListNode * n);
	private:
		int value;
		ListNode * next;
};

#endif
