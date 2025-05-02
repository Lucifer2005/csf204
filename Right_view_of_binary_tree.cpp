// C++ program to print right view of Binary Tree
// using recursion
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

void RecursiveRightView(Node* root, int level, int& maxLevel, vector<int>& result) {
    if (!root) return;

    // If current level is more than max level,
    // this is the first node of that level
    if (level > maxLevel) {
        result.push_back(root->data);
        maxLevel = level;
    }

    // Traverse right subtree first, then left subtree
    RecursiveRightView(root->right, level + 1,
                       maxLevel, result);
    RecursiveRightView(root->left, level + 1,
                       maxLevel, result);
}

// Function to return the right view of the binary tree
vector<int> rightView(Node *root) {
    vector<int> result;
    int maxLevel = -1;

    // Start recursion with root at level 0
    RecursiveRightView(root, 0, maxLevel, result);
    
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
    //           / \   
    //          4   5  
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);
    printArray(result);
    return 0;
}