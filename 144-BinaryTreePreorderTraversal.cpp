/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
	void preorder(TreeNode *root, vector<int> &store) {
		if (root) {
			store.push_back(root->val);
			preorder(root->left, store);
			preorder(root->right, store);
		} else {
			return;
		}		
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		preorder(root, result);
		return result;
	}
};

int main() {
	int elements[10] = {4, 5, 2, 1, 0, 9, 3, 7, 6, 8};
	TreeNode* tree = NULL; 
	CreateBST(tree, elements, 10);
	printf("Root value is %d\n", tree->val);

	printf("Pre order:\n");
	PreTraverse(tree);
	printf("\nMid order:\n");
	MidTraverse(tree);
	printf("\nPost order:\n");
	PostTraverse(tree);
	printf("\n");
	Solution s;
	vector<int> result = s.preorderTraversal(tree);
	
	for (size_t i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}

