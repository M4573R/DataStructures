#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <assert.h>
#include "Node.h"

using namespace std;

class Trie {
	public:
		Trie();
		~Trie();
		void insert(string s);
		bool find(string s);
	private:
		Node * root;
		friend class Node;
};

#endif