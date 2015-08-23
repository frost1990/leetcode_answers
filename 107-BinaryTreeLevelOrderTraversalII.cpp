/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
	vector <vector <int> > levelOrderBottom(TreeNode* root) {
		vector <vector <int> > result;
		if (root == NULL) {
			return result;
		}

		vector<TreeNode *> store;
		store.push_back(root);
		int visited = 0;
		int lastlevel = 0;

		while (visited < store.size()) {
			lastlevel = store.size();
			vector<int> level;
			while (visited < lastlevel) {
				level.push_back(store[visited]->val);
				printf("Visit %d\n", store[visited]->val);
				if (store[visited]->left != NULL) {
					store.push_back(store[visited]->left);
				}
					
				if (store[visited]->right != NULL) {
					store.push_back(store[visited]->right);
				}
				visited++;
			}
			result.push_back(level);
		}

		vector <vector <int> > ret;
		for (size_t i = 0; i < result.size(); i++) {
			ret.push_back(result[result.size() - 1 - i]);
		}
		return ret;
	}
};

int main() {
	TreeNode t1(1), t2(2), t3(3), t4(4), t5(5), t6(6), t7(7), t8(8), t9(9), t10(10);
	t4.left = &t2;
	t4.right = &t5;

	t2.left = &t1;
	t2.right = &t3;

	t5.right = &t9;
	t5.left = &t10;

	t9.left = &t7;
	t7.left = &t6;
	t7.right = &t8;
	
	Solution s;
	vector <vector<int> > ret = s.levelOrderBottom(&t4);

	for (size_t i = 0; i < ret.size(); i++) {
		for (size_t j = 0; j < ret[i].size(); j++) {
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}
