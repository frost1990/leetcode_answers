/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* getleftside(TreeNode *root) {
		if (root == NULL) {
			return NULL;
		}
		TreeNode *p = root;
		TreeNode *q = root;
		while (p->left != NULL) {
			p = p->left;
		}
		return p;
	}

	TreeNode* getrightside(TreeNode *root) {
		if (root == NULL) {
			return NULL;
		}
		TreeNode *p = root;
		while (p->right != NULL) {
			p = p->right;
		}
		return p;
	}

	bool isValidBST(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		if (root->right != NULL)	{
			if (root->val >= getleftside(root->right)->val) {
				return false; 
			} 
		}
		if (root->left != NULL) {
			if (root->val <= getrightside(root->left)->val) {
				return false; 
			} 
		}

		return isValidBST(root->left) && isValidBST(root->right);
	}
};

int main() {
	//TreeNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(6), t7(7), t8(8), t9(9);
	TreeNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(0), t7(7), t8(8), t9(9);
	t4.left = &t2;
	t4.right = &t5;

	t2.left = &t1;
	t2.right = &t3;

	t5.right = &t9;

	t9.left = &t7;
	t7.left = &t6;
	t7.right = &t8;
	
	Solution s;
	bool ret = s.isValidBST(&t4);
	printf("Return value is %s\n", ret? "true": "false");
	
	return 0;
}
