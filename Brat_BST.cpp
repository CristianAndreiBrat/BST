#include<iostream>
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

int main() {

    return 0;
}
