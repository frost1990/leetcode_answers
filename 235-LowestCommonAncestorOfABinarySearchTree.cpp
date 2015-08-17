/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

/**
  Definition for a binary tree node.
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

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) {
			return NULL;
		}
		int valp = p->val;
		int valq = q->val;
		int valr = root->val;
		if ( (valp < valr && valr < valq) || (valq < valr && valr < valp)) {
			return root;
		} else if ((valp < valq && valq < valr) || (valq < valp  && valp < valr)) {
			printf("Will call lowestCommonAncestor(%d, %d, %d)\n", root->left->val, p->val, q->val);
			return lowestCommonAncestor(root->left, p, q);
		} else if (valq == valr || valp == valr) {
			printf("p = %d, q = %d Will return root %d\n", p->val, q->val, root->val);
			return root;
		} else {
			printf("Will call lowestCommonAncestor(%d, %d, %d)\n", root->right->val, p->val, q->val);
			return lowestCommonAncestor(root->right, p, q);
		}
	}
};


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
	printf("Tree node value is %d\n", s.lowestCommonAncestor(&t4, &t2, &t4)->val);
	
	return 0;
}
