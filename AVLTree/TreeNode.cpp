#include "TreeNode.h"

TreeNode::TreeNode() {
	value = 0;
	parent = NULL;
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(int v) {
	value = v;
	parent = NULL;
	left = NULL;
	right = NULL;
}

TreeNode::~TreeNode() {
	delete left;
	delete right;
}