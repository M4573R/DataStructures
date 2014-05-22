#include "Node.h"

Node::Node() {
	value = '\00';
	for (int i=0; i<255; i++) {
		children[i] = NULL;
	}
}

Node::Node(char node_val) {
	value = node_val;
	for (int i=0; i<255; i++) {
		children[i] = NULL;
	}	
}

Node::~Node() {
	for (int i=0; i<255; i++) {
		delete children[i];
	}
}