#include <assert.h>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::BinarySearchTree(int * arr) {
	root = NULL;
	cout << sizeof(arr)/sizeof(*arr);
	for (int i = 0; i < (sizeof(arr)/sizeof(*arr)); i++) {
		cout << arr[i] << ",";
		insert(arr[i]);
	}
}

BinarySearchTree::~BinarySearchTree() {
	delete root;
}

void BinarySearchTree::insert(int v) {
	insert(root, v);
}

void BinarySearchTree::insert(TreeNode*& node, int v) {
	if (node == NULL) {
		node = new TreeNode(v);
		TreeNode * parent = find_parent(v);
		node->parent = parent;
		num_nodes++;
	}

	else if (v > node -> value) {
		insert(node->right, v);
	}

	else if (v < node -> value) {
		insert(node->left, v);
	}

	else {
		return; // do nothing
	}
}

TreeNode * BinarySearchTree::find_parent(int v) {
	return find_parent(root, NULL, v);
}

TreeNode * BinarySearchTree::find_parent(TreeNode*& node, TreeNode* parent, int v) {
	if (node == NULL) {
		return NULL;
	}

	else if (node->value != v) {
		parent = find_parent(node->left, node, v);
		if (parent == NULL) {
			parent = find_parent(node->right, node, v);
		}
	}
	return parent;
}

bool BinarySearchTree::find(int v) {
	return (find(root, v) != NULL);
}

TreeNode * BinarySearchTree::find(TreeNode*& node, int v) {
	if (node == NULL) {
		return node;
	}

	if (node -> value == v) {
		return node;
	}

	else if (v > node -> value) {
		return find(node->right, v);
	}

	else {
		return find(node->left, v);
	}	

}

void BinarySearchTree::remove(int v) {
	remove(root, v);
}

TreeNode * BinarySearchTree::find_min(TreeNode* node) {
	while (node -> left != NULL) {
		node = node -> left;
	}
	return node;
}

void BinarySearchTree::replace_node(TreeNode * node1, TreeNode * node2) {
	if (node1 -> parent != NULL) {
		if (node1 == node1->parent->left) {
			node1 -> parent -> left = node2;
		}
		else {
			node1 -> parent -> right = node2;	
		}
	}

	if (node2 != NULL) {
		node2 -> parent = node1 -> parent;
	}
}

void BinarySearchTree::remove(TreeNode* node, int v) {
	if (v < node->value) {
		remove(node->left,v);
	}
	else if (v > node->value) {
		remove(node->right,v);
	}
	else {
		if (node->left && node->right) {
			TreeNode * n = find_min(node->right);
			v = n->value;
			remove(n, n->value);
		}
		else if (node->left) {
			replace_node(node, node->left);
		}
		else if (node->right) {
			replace_node(node, node->right);
		}
		else {
			replace_node(node, NULL);
		}
	}
}

void BinarySearchTree::print_tree() {
	return print_tree(root);
	cout << endl;
	cout << "number of nodes: " << num_nodes << endl;
}

void BinarySearchTree::print_tree(TreeNode*& node) {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
		return;
	}
	if (node != NULL) {
		cout << node -> value << " ";
	}
	if (node -> left != NULL) {
		print_tree(node->left);
	}

	if (node -> right != NULL) {
		print_tree(node->right);
	}

}