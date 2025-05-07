#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* parent;
    Node* children[2];

    Node(int value) {
        data = value;
        parent = nullptr;
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Tree {
public:
    Node* root;
    vector<Node*> nodes;

    Tree() {
        root = nullptr;
    }

    void addNode(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            nodes.push_back(newNode);
            return;
        }

        for (Node* n : nodes) {
            if (!n->children[0]) {
                n->children[0] = newNode;
                newNode->parent = n;
                nodes.push_back(newNode);
                return;
            } else if (!n->children[1]) {
                n->children[1] = newNode;
                newNode->parent = n;
                nodes.push_back(newNode);
                return;
            }
        }
    }

    void printTree() {
        printRecursive(root, 0);
    }

private:
    void printRecursive(Node* node, int space) {
        if (!node) return;
        const int indent = 6;
        printRecursive(node->children[1], space + indent);

        for (int i = 0; i < space; i++) cout << ' ';
        cout << node->data << "\n";

        printRecursive(node->children[0], space + indent);
    }
};

int main() {
    Tree tree;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Add Node\n";
        cout << "2. Print Tree\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            tree.addNode(value);
            cout << "Node added.\n";
        } else if (choice == 2) {
            cout << "\nTree structure (rotated 90° left):\n";
            tree.printTree();
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
