/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */

#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) {
			return true;
		} else if ((p == NULL) || (q == NULL) ) {
			return false;
		}

		if (p->val != q->val) {
			return false;
		}

		if (p->left == NULL && q->left != NULL) {
			return false;
		}

		if (p->right == NULL && q->right != NULL) {
			return false;
		}

		if (q->left == NULL && p->left != NULL) {
			return false;
		}

		if (q->right == NULL && p->right != NULL) {
			return false;
		}

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

/*
			4
		2		5
	1		3		9
				7
*/

int main() {
	TreeNode t1(1), t2(2), t3(3), t4(4), t5(2), t6(6), t7(7), t8(8), t9(3), t10(1);
	t4.left = &t2;
	t4.right = &t5;

	t2.left = &t1;
	t2.right = &t3;

	t5.right = &t9;
	t5.left = &t10;

	//t9.left = &t7;
	//t7.left = &t6;
	//t7.right = &t8;
	
	Solution s;
	bool ret = s.isSameTree(NULL, NULL);
	printf("Return value is %s\n", ret ? "true":"false");

	return 0;
}
