#include "ListNode.h"

ListNode::ListNode() {
	value = 0;
	next = NULL;
}

ListNode::ListNode(int v) {
	value = v;
	next = NULL;
}

int ListNode::get_value() {
	return value;
}

ListNode * ListNode::get_next() {
	return next;
}

void ListNode::set_value(int v) {
	value = v;
}

void ListNode::set_next(ListNode * n) {
	next = n;
}