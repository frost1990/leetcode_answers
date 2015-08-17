/*Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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
#include <string>
#include <string.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

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

class Solution {
public:
	void ShowPath(TreeNode *root, vector<string> &store, string path) {
		if (root == NULL) {
			return;
		} 
		char buffer[128] = {0};
		snprintf(buffer, sizeof(buffer) - 1, "%d", root->val);
		path.append(string(buffer));
		// It is a leaf.
		if (root->left == NULL && root->right == NULL) {
			store.push_back(path);	
		} else {
			path.append("->");
			ShowPath(root->left, store, path);
			ShowPath(root->right, store, path);
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		string path;
		ShowPath(root, result, path);
		return result;
	}
};

int main() {
	Solution s;
	int elements[10] = {4, 5, 2, 1, 0, 9, 3, 7, 6, 8};
	TreeNode* tree = NULL; 
	CreateBST(tree, elements, 10);
	printf("Root value is %d\n", tree->val);

	vector<string> result = s.binaryTreePaths(tree);

	for (size_t i = 0; i < result.size(); i++) {
		printf("%s\n", result[i].c_str());
	}

	return 0;
}
