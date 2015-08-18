/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
	int maxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int lh = maxDepth(root->left);
		int rh = maxDepth(root->right);

		if (lh >= rh) {
			return lh + 1;
		} else {
			return rh + 1;
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
	int ret = s.maxDepth(&t4);
	
	printf("Return value is %d\n", ret);

	return 0;
}
