/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
	int minDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}

		int lh = minDepth(root->left);
		int rh = minDepth(root->right);

		if ((0 < lh) && (lh <= rh)) {
			return lh + 1;
		} else if ((0 < rh) && (rh <= lh)) {
			return rh + 1;
		} else if (lh == 0) {
			return rh + 1;
		} else {
			return lh + 1;
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
//	t2.right = &t3;

	t5.right = &t9;

	t9.left = &t7;
	t7.left = &t6;
	t7.right = &t8;
	
	Solution s;
	int ret = s.minDepth(&t2);
	
	printf("Return value is %d\n", ret);

	return 0;
}
