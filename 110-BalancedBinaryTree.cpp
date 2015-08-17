/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
	int Height(TreeNode *root)  {  
		if (root == NULL) {
			return 0;
		}

		int lh = Height(root->left);
		int rh = Height(root->right);
		if (lh >= rh) {
			return lh + 1;
		} else {
			return rh + 1;
		}		
	}

	bool isBalanced(TreeNode* root) {
		if (root == NULL) {
			return true;
		}

		int lh = Height(root->left);
		int rh = Height(root->right);

		if ((lh - rh > 1) || (rh -lh > 1)) {
			printf("val %d lh %d, rh %d, false\n", root->val, lh, rh);
			return false;
		} else {
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}
};

/*
			4
		2		5
	1		3		9
				7
*/

int main() {
	TreeNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(6), t7(7), t8(8), t9(9);
	t4.left = &t2;
	t4.right = &t5;

	t2.left = &t1;
	t2.right = &t3;

	t5.right = &t9;

	t9.left = &t7;
	t7.left = &t6;
	t7.right = &t8;
	
	Solution s;
	bool ret = s.isBalanced(&t4);
	
	printf("Return value is %s\n", ret ? "true":"false");

	return 0;
}
