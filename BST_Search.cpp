#include <iostream>
using namespace std;

class Node {
	public:
    		int key;
    		Node* left;
    		Node* right;
    		Node(int item) {
        		key = item;
        		left = right = NULL;
    		}
};

bool search(Node* root, int value) {
    if (root == NULL)
		return false;
    else if (root->key == value)
        	return true;
    else if (root->key < value)
        	return search(root->right, value);
    else
		return search(root->left, key);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    if(search(root, 19))
		 cout << "Found\n";
    else
		cout << "Not Found\n";
    if(search(root, 80))
		cout << "Found\n"; 
    else
		cout << "Not Found\n";
    return 0;
}