#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "TreeNode.h"

using namespace std;

class AVLTree {
	public:
		AVLTree();
		AVLTree(int * arr);
		~AVLTree();
		void insert(int v);
		unsigned int balance_factor(TreeNode*& node);
		void balance(TreeNode*& node);
		void rotate_left(TreeNode*& node);
		void rotate_right(TreeNode*& node);
		bool find(int v);
		void remove(int v);
		void print_tree();
		TreeNode * find_parent(int v);
	private:
		TreeNode * root;
		int num_nodes;
		void insert(TreeNode*& node, int v);
		TreeNode * find(TreeNode*& node, int v);
		void remove(TreeNode* node, int v);
		void print_tree(TreeNode*& root);
		TreeNode * find_min(TreeNode* node);
		void replace_node(TreeNode * node1, TreeNode * node2);
		TreeNode * find_parent(TreeNode*& node, TreeNode* parent, int v);
};

#endif