/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
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
		void OrderTraverse(TreeNode *tree, vector <int> &store) {  
			if (tree) {  
				OrderTraverse(tree->left, store);  
				store.push_back(tree->val);
				OrderTraverse(tree->right, store);  
			}  
		}

		int kthSmallest(TreeNode* root, int k) {
			if (root == NULL) {
				return 0;
			}	

			vector <int> store;
			OrderTraverse(root, store);
			return store[k - 1];
		}
};

int main() {
	//int elements[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
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
	int ret = s.kthSmallest(tree, 5);
	
	printf("Return value is %d\n", ret);
	
	return 0;
}
