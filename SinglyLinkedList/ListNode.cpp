#include "ListNode.h"

ListNode::ListNode() {
	value = 0;
	next = NULL;
}

ListNode::ListNode(int v) {
	value = v;
	next = NULL;
}

ListNode::~ListNode() {
	delete next;
}
