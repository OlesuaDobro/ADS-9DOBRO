#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
template <typename T>
class bst {
 public:
    bst() {
        root = nullptr;
    }
    struct node {
        T data;
        int count;
        node* left;
        node* right;
        node(const T& data) {
            this->data = data;
            count = 1;
            left = nullptr;
            right = nullptr;
        }
    };
    void insert(const T& data);
    void inorderTraversal() const;
    int size() const;
    ~bst();
 private:
    node* root;
    void insertNode(node*& node, const T& data);
    void inorderTraversalNode(node*& node) const;
    int sizeNode(node* node) const;
};

bst<string> makeTree(const char* filename);
template <typename T>
bst<T>::~bst() {
    if (root) {
        deleteTree(root);
    }
}
template <typename T>
void bst<T>::insert(const T& data) {
    insertNode(root, data);
}
template <typename T>
void bst<T>::insertNode(node*& node, const T& data) {
    if (node == nullptr) {
        node = new node(data);
        return;
    }
    if (data < node->data) {
        insertNode(node->left, data);
    } else if (data > node->data) {
        insertNode(node->right, data);
    } else {
        node->count++;
    }
}
template <typename T>
void bst<T>::inorderTraversal() const {
    inorderTraversalNode(root);
}
template <typename T>
void bst<T>::inorderTraversalNode(node* node) const {
    if (node != nullptr) {
        inorderTraversalNode(node->left);
        cout << node->data << " : " << node->count << endl;
        inorderTraversalNode(node->right);
    }
}
template <typename T>
int bst<T>::size() const {
    return sizeNode(root);
}
template <typename T>
int bst<T>::sizeNode(node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + sizeNode(node->left) + sizeNode(node->right);
}
bst<string> makeTree(const char* filename) {
    bst<string> tree;
    ifstream file(filename);
    string value;
    while (file >> value) {
        tree.insert(value);
    }
    file.close();
    return tree;
}
