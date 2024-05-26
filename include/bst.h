#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
template <typename T>
class BST {
 public:
    BST() {
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
    ~BST();
 private:
    node* root;
    void insertNode(node*& node, const T& data);
    void inorderTraversalNode(node*& node) const;
    int sizeNode(node* node) const;
};

BST<string> makeTree(const char* filename);
template <typename T>
BST<T>::~BST() {
    if (root) {
        deleteTree(root);
    }
}
template <typename T>
void BST<T>::insert(const T& data) {
    insertNode(root, data);
}
template <typename T>
void BST<T>::insertNode(node*& node, const T& data) {
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
void BST<T>::inorderTraversal() const {
    inorderTraversalNode(root);
}
template <typename T>
void BST<T>::inorderTraversalNode(node* node) const {
    if (node != nullptr) {
        inorderTraversalNode(node->left);
        cout << node->data << " : " << node->count << endl;
        inorderTraversalNode(node->right);
    }
}
template <typename T>
int BST<T>::size() const {
    return sizeNode(root);
}
template <typename T>
int BST<T>::sizeNode(node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + sizeNode(node->left) + sizeNode(node->right);
}
BST<string> makeTree(const char* filename) {
    BST<string> tree;
    ifstream file(filename);
    string value;
    while (file >> value) {
        tree.insert(value);
    }
    file.close();
    return tree;
}

#endif  // INCLUDE_BST_H_
