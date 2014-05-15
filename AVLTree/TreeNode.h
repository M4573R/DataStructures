#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

class TreeNode {
	public:
		TreeNode();
		TreeNode(int v);
		~TreeNode();
	private:
		int value;
		TreeNode * parent;
		TreeNode * left;
		TreeNode * right;
		friend class BinarySearchTree;
};

#endif