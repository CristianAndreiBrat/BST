#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    Node(Node& other) {
        value = other.value;
        left = other.left;
        right = other.right;
    }
    Node(Node* other) {
        if (other != nullptr) {
            value = other->value;
            left = other->left;
            right = other->right;
        } else {
            value = 0;
            left = nullptr;
            right = nullptr;
        }
    }
};
struct BST {
    Node* root;
    BST() {
        root = nullptr;
    }
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value)
            node->left = insertRecursive(node->left, value);
        else if (value > node->value)
            node->right = insertRecursive(node->right, value);
        return node;
    }
    void insertRecursive(int value) {
        root = insertRecursive(root, value);
    }
    void insertIterative(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;
        Node* parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (value < current->value)
                current = current->left;
            else if (value > current->value)
                current = current->right;
            else
                return;
        }
        if (value < parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    Node* searchRecursive(Node* node, int value) {
        if (node == nullptr || node->value == value)
            return node;

        if (value < node->value)
            return searchRecursive(node->left, value);
        else
            return searchRecursive(node->right, value);
    }
    Node* searchRecursive(int value) {
        return searchRecursive(root, value);
    }
    Node* searchIterative(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (current->value == value)
                return current;
            if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
    void printInOrder() {
        cout << "In-Order: ";
        inOrder(root);
        cout << endl;
    }
    void printPreOrder() {
        cout << "Pre-Order: ";
        preOrder(root);
        cout << endl;
    }
    void printPostOrder() {
        cout << "Post-Order: ";
        postOrder(root);
        cout << endl;
    }
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->value)
            node->left = deleteNode(node->left, value);
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }

        return node;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }
};

int main() {

    return 0;
}
