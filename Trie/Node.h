#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
	public:
		Node();
		Node(char node_val);
		~Node();
	private:
		char value;
		Node * children[255];
		friend class Trie;
};

#endif