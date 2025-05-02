#include <iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Function to calculate the sum of nodes at kth level in a binary tree
int sumAtKthLevel(TreeNode* root, int k, int level = 0) {
	if (root == NULL) {
		return 0;
	}
	if (level == k) {
		return root->val;
	}
	return sumAtKthLevel(root->left, k, level + 1) + sumAtKthLevel(root->right, k, level + 1);
}

// Driver code
int main() {
	// Example binary tree
	TreeNode* root = new TreeNode(50);
	root->left = new TreeNode(30);
	root->right = new TreeNode(70);
	root->left->left = new TreeNode(20);
	root->left->right = new TreeNode(40);
	root->right->left = new TreeNode(60);
	

	int k = 2;
	int sum = sumAtKthLevel(root, k);

	cout << "The sum of nodes at level " << k << " is " << sum << endl;

	return 0;
}
