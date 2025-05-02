#include <iostream>
using namespace std;

class Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

void insert(Node** root, int value) {
    	if (*root == NULL)
		{
		Node *temp=new Node(value); 
        	*root=temp;
		return;
		}    
  	if (root->key > value) 
        	insert(root->left, value);
        else 
        	insert(root->right, value);
    	}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
    return 0;
}