/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty()) {
			return NULL;
		}

		return dobuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	// inorder: 	 4 7 2 |1| 5 3 8 6
	// postorder: 	 7 4 2 5 8 6 3 |1|
    TreeNode* dobuildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend) {
		if ((instart > inend) || (poststart > postend)) {
			return NULL;
		}

		printf("instart %d, inend %d, poststart %d, postend %d\n", instart, inend, poststart, postend);
		size_t rootval = postorder[postend];
		TreeNode* root = new TreeNode(rootval);
		size_t root_idx = 0;
		for (size_t i = instart; i <= inend; i++) {
			if (inorder[i] == rootval) {
				root_idx = i;	
				break;
			}
		}

		root->left = dobuildTree(inorder,  instart, root_idx - 1, postorder, poststart, poststart + root_idx - instart - 1);
		root->right = dobuildTree(inorder, root_idx + 1, inend, postorder, poststart + root_idx - instart, postend - 1);

		return root;
    }
};

int main() {
	vector<int> inorder, postorder;
	size_t in[8] = {4, 7, 2, 1, 5, 3, 8, 6};
	size_t post[8] = {7, 4, 2, 5, 8, 6, 3, 1};

	for (size_t i = 0; i < 8; i++) {
		inorder.push_back(in[i]);	
	}
	for (size_t i = 0; i < 8; i++) {
		postorder.push_back(post[i]);	
	}

	printf("In order:\n");
	print_vector(inorder);

	printf("Post order:\n");
	print_vector(postorder);

	Solution s;
	TreeNode *tree = s.buildTree(inorder, postorder) ;

	printf("Pre order:\n");
	PreTraverse(tree);
	printf("\nIn order:\n");
	InTraverse(tree);
	printf("\nPost order:\n");
	PostTraverse(tree);
	printf("\n");

	return 0;
}
