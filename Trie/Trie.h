#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <assert.h>
#include <string>
#include "Node.h"

using namespace std;

class Trie {
	public:
		Trie();
		~Trie();
		void insert(string s);
		Node * find(string s, Node*& start);
		bool find(string s);
		void remove(string s);
	private:
		Node * root;
		friend class Node;
};

#endif