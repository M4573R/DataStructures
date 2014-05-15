#include "ListIterator.h"

ListIterator::ListIterator() {
	current = NULL;
}

ListIterator::ListIterator(ListNode * curr) {
	current = curr;
}

ListNode * ListIterator::get_current() {
	return current;
}

void ListIterator::set_current(ListNode * n) {
	current = n;
}

void ListIterator::move_forward() {
	current = current -> get_next();
}