/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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

bool InsertBST(TreeNode * &tree, int element) {  
	if (tree == NULL) {  
		tree = new TreeNode(element);  
		return true;  
	}  

	if (element == tree->val) { 
		return false;  
	} else if (element < tree->val)  { 
		return InsertBST(tree->left, element);  
	} else {
		return InsertBST(tree->right, element); 
	}
}  

void CreateBST(TreeNode * &tree, int a[], int n)  {  
	tree = NULL;   
	for (int i = 0; i < n; i++) {  
		InsertBST(tree, a[i]);  
	}
}  

void PreTraverse(TreeNode *tree) {  
	if (tree) {  
		printf("%d ", tree->val);  
		PreTraverse(tree->left);  
		PreTraverse(tree->right);  
	}
}  
  
void MidTraverse(TreeNode *tree) {  
	if (tree) {  
		MidTraverse(tree->left);  
		printf("%d ", tree->val);  
		MidTraverse(tree->right);  
	} 
}  

void PostTraverse(TreeNode *tree) {  
	if (tree) {  
		MidTraverse(tree->left);  
		MidTraverse(tree->right);  
		printf("%d ", tree->val);  
	}
}

class Solution {
public:
	int GetDepth(TreeNode *root)  {  
		TreeNode *tree = root;
		int depth = 0;  
		while (tree)  {  
			tree = tree->left;
			depth++;  
		}  
		return depth;  
	}  

	int countNodes(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}

		int ldepth = GetDepth(root->left);
		int rdepth = GetDepth(root->right);

		// A complete binary tree has 2^h - 1 internal nodes, there must be at least one part is full
		if (ldepth == rdepth) {
			// In this case, left part is full
			return (1 << ldepth) + countNodes(root->right);
		} else {
			// In this case, left part may not full, but right part is full
			return (1 << rdepth) + countNodes(root->left);
		}
	}
};

int main() {
	Solution s;
	int elements[10] = {4, 5, 2, 1, 0, 9, 3, 7, 6, 8};
	TreeNode* tree = NULL; 
	CreateBST(tree, elements, 10);
	printf("Root value is %d, depth is %d\n", tree->val, s.GetDepth(tree));

	printf("Pre order:\n");
	PreTraverse(tree);
	printf("\nMid order:\n");
	MidTraverse(tree);
	printf("\nPost order:\n");
	PostTraverse(tree);
	printf("\n");

	int ret = s.countNodes(tree);
	printf("Return value is %d\n", ret);
	return 0;
}
