/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

void print_vector(vector<int> source) {
	for (size_t i = 0; i < source.size(); i++) {
		printf("%d ", source[i]);
	}
	printf("\n");
}

void PreTraverse(TreeNode *tree) {  
	if (tree) {  
		printf("%d ", tree->val);  
		PreTraverse(tree->left);  
		PreTraverse(tree->right);  
	}
}  
  
void InTraverse(TreeNode *tree) {  
	if (tree) {  
		InTraverse(tree->left);  
		printf("%d ", tree->val);  
		InTraverse(tree->right);  
	} 
}  

void PostTraverse(TreeNode *tree) {  
	if (tree) {  
		PostTraverse(tree->left);  
		PostTraverse(tree->right);  
		printf("%d ", tree->val);  
	}
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) {
			return NULL;
		}

		return dobuildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

    TreeNode* dobuildTree(vector<int>& preorder, size_t prestart,  size_t preend, vector<int>& inorder, size_t instart, size_t inend) {
		if ((prestart > preend) || (instart > inend)) {
			return NULL;
		}

		printf("prestart %lu, preend, %lu, instart %lu, inend %lu\n", prestart, preend, instart, inend);
		int rootval = preorder[prestart];
		TreeNode* root = new TreeNode(rootval);
		int root_idx = 0;
		for (size_t i = instart; i <= inend; i++) {
			if (inorder[i] == rootval) {
				root_idx = i;	
				break;
			}
		}

		root->left = dobuildTree(preorder, prestart + 1, prestart + root_idx - instart, inorder, instart, root_idx - 1);
		root->right = dobuildTree(preorder, prestart + root_idx - instart + 1, preend, inorder, root_idx + 1, inend);

		return root;
    }
};

int main() {
	vector<int> preorder, inorder;
	int pre[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int in[8] = {4, 7, 2, 1, 5, 3, 8, 6};

	for (int i = 0; i < 8; i++) {
		preorder.push_back(pre[i]);	
	}
	for (int i = 0; i < 8; i++) {
		inorder.push_back(in[i]);	
	}
	printf("Pre order:\n");
	print_vector(preorder);

	printf("In order:\n");
	print_vector(inorder);

	Solution s;
	TreeNode *tree = s.buildTree(preorder, inorder) ;

	printf("Pre order:\n");
	PreTraverse(tree);
	printf("\nIn order:\n");
	InTraverse(tree);
	printf("\nPost order:\n");
	PostTraverse(tree);
	printf("\n");

	return 0;
}
