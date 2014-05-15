#include "ListIterator.h"

ListIterator::ListIterator() {
	current = NULL;
}

ListIterator::ListIterator(ListNode * curr) {
	current = curr;
}

void ListIterator::move_forward() {
	current = current -> next;
}