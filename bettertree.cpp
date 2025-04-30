#include <iostream>
using namespace std;

struct Node {
    float value;
    Node* left;
    Node* right;

    Node(float val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void printTreeVisual(Node* root, int depth = 0) {
    if (!root) return;

    printTreeVisual(root->right, depth + 1);

    for (int i = 0; i < depth; ++i) cout << "    ";
    cout << root->value << endl;

    printTreeVisual(root->left, depth + 1);
}

int main() {
    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(15);

    root->right->left = new Node(12);
    root->right->right = new Node(128);

    root->right->right->left = new Node(13);
    root->right->right->left->right = new Node(14);
    root->right->right->left->right->left = new Node(12.5);
    root->right->right->left->right->right = new Node(14.5);

    printTreeVisual(root);

    return 0;
}
