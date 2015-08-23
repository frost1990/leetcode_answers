/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool compare(TreeNode *left, TreeNode *right) {
		if (left == NULL && right != NULL) {
			return false;
		} else if (left != NULL && right == NULL) {
			return false;
		} else if (left == NULL && right == NULL) {
			return true;
		} else {
			if (left->val != right->val) {
				return false;	
			}
			return compare(left->left, right->right) && compare(left->right, right->left);
		}
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		return compare(root->left, root->right);
	}
};

int main() {
	TreeNode t1(1), t2(3), t3(3), t4(4), t5(3), t6(6), t7(7), t8(8), t9(1);
	t4.left = &t2;
	t4.right = &t5;

	t2.left = &t1;

	t5.right = &t9;

	Solution s;
	bool ret = s.isSymmetric(&t1);
	printf("Return value is %s\n", ret? "true": "false");
	return 0;
}

