// C++ program to print left view of Binary Tree
// using resursion
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
// Helper function for the left view using Recursion
void RecLeftView(Node* root, int level, 
                 int& maxLevel, vector<int>& result) {
    if (!root) return;

    // If current level is more than max level,
    // this is the first node of that level
    if (level > maxLevel) {
        result.push_back(root->data);
        maxLevel = level;
    }
    // Traverse left subtree first, then right subtree
    RecLeftView(root->left, level + 1, maxLevel, result);
    RecLeftView(root->right, level + 1, maxLevel, result);
}

// Function to return the left view of the binary tree
vector<int> leftView(Node *root) {
    vector<int> result;
    int maxLevel = -1;
    // Start recursion with root at level 0
    RecLeftView(root, 0, maxLevel, result);
    return result;
}
void printArray(vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    // Representation of the input tree:
    //         1
    //        / \
    //       2   3
    //      / \   
    //     4   5 
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = leftView(root);
    printArray(result);
    return 0;
}