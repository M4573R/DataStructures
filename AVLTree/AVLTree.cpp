#include <assert.h>
#include "AVLTree.h"

AVLTree::AVLTree() {
	root = NULL;
}

// AVLTree::AVLTree(int * arr) {
// 	root = NULL;
// 	cout << sizeof(arr)/sizeof(*arr);
// 	for (int i = 0; i < (sizeof(arr)/sizeof(*arr)); i++) {
// 		cout << arr[i] << ",";
// 		insert(arr[i]);
// 	}
// }

AVLTree::~AVLTree() {
	delete root;
}

unsigned int AVLTree::balance_factor(TreeNode*& node) {
	return 1+(node == NULL ? 0: max(balance_factor(node->left), balance_factor(node->right)));
}

void AVLTree::insert(int v) {
	insert(root, v);
}

void AVLTree::insert(TreeNode*& node, int v) {
	if (node == NULL) {
		node = new TreeNode(v);
		TreeNode * parent = find_parent(v);
		node->parent = parent;
		num_nodes++;
		balance(root);
		return;
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

void AVLTree::balance(TreeNode*& node) {
	if (balance_factor(root) == 2) {
		TreeNode * l = node->left;
		if (balance_factor(l) == -1) {
			rotate_left(l);
		}
		rotate_right(node);
	}
	else {
		TreeNode * r = node->right;
		if (balance_factor(r) == 1) {
			rotate_right(r);
		}
		rotate_left(node);
	}
}

void AVLTree::rotate_left(TreeNode*& node) {
	TreeNode* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	node = tmp;
}

void AVLTree::rotate_left_twice(TreeNode*& node) {
	TreeNode* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	node = tmp;
}

void AVLTree::rotate_right(TreeNode*& node) {
	TreeNode* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	node = tmp;
}

TreeNode * AVLTree::find_parent(int v) {
	return find_parent(root, NULL, v);
}

TreeNode * AVLTree::find_parent(TreeNode*& node, TreeNode* parent, int v) {
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

bool AVLTree::find(int v) {
	return (find(root, v) != NULL);
}

TreeNode * AVLTree::find(TreeNode*& node, int v) {
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

void AVLTree::remove(int v) {
	remove(root, v);
}

TreeNode * AVLTree::find_min(TreeNode* node) {
	while (node -> left != NULL) {
		node = node -> left;
	}
	return node;
}

void AVLTree::replace_node(TreeNode * node1, TreeNode * node2) {
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

void AVLTree::remove(TreeNode* node, int v) {
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

void AVLTree::print_tree() {
	return print_tree(root);
	cout << endl;
	cout << "number of nodes: " << num_nodes << endl;
}

void AVLTree::print_tree(TreeNode*& node) {
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