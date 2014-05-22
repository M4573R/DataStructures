#include "Trie.h"

Trie::Trie() {
	root = new Node('\00');
}

Trie::~Trie() {
	delete root;
}

void Trie::insert(string s) {
	Node * tmp = root;
	for(int i = 0; i < s.length(); i++) {
		if (tmp -> children[ (unsigned int) s[i] ] == NULL) {
			tmp -> children[ (unsigned int) s[i] ] = new Node(s[i]);
		}
		tmp = tmp -> children[ (unsigned int) s[i] ];
	}
}

bool Trie::find(string s) {
	assert(root != NULL);
	Node * tmp = new Node();
	tmp = root;
	for(int i = 0; i <= s.length(); i++) {
		if (i == s.length() && (tmp -> value == s[i - 1]) ) {
			return true;
		}
		else if (tmp -> children[ (unsigned int) s[i] ] == NULL) {
			return false;
		}
		else {
			tmp = tmp -> children[ (unsigned int) s[i] ];
		}
	}
	delete tmp;
	return false;
}