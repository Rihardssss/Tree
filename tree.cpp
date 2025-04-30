#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void printTree(Node* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main() {
    Node* root = new Node(10);          
    root->left = new Node(5);            
    root->right = new Node(15);          

    
    cout << "Koks: ";
    printTree(root);
    cout << endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
