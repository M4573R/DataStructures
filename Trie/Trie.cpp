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

Node * Trie::find(string s, Node*& start) {
	assert(root != NULL);
	Node * tmp = new Node();
	tmp = start;
	for(int i = 0; i <= s.length(); i++) {
		if (i == s.length() && (tmp -> value == s[i - 1]) ) {
			return tmp;
		}
		else if (tmp -> children[ (unsigned int) s[i] ] == NULL) {
			return NULL;
		}
		else {
			tmp = tmp -> children[ (unsigned int) s[i] ];
		}
	}
	delete tmp;
	return NULL;
}

bool Trie::find(string s) {
	return (find(s, root) != NULL ? true : false);
}

void Trie::remove(string s) {
	if (!find(s)) {
		cout << "ERROR: String not contained within Trie" << endl;
		return;
	}
	Node * tmp = find(s, root);
	Node * tmp2 = find(s.substr(0, s.length() - 1), root);
	tmp2 -> children[ (unsigned int) tmp->value ] = NULL;
	delete tmp;

	for (int i = 0; i < 255; i++) {
		if (tmp2 -> children[i] != NULL) {
			return;
		}
	}
	remove( s.substr(0, s.length() - 1) );
}
