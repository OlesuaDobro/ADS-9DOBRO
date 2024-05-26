// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
template <typename T>
class BST {
 private:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
    };
    Node* root;
    int depthThree(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(depthThree(root->left), depthThree(root->right)) + 1;
    }
    Node* addN(Node* root, const T& data) {
        if (root == nullptr) {
            root = new Node;
            root->data = data;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->data > data) {
            root->left = addN(root->left, data);
        } else if (root->data < data) {
            root->right = addN(root->right, data);
        } else {
            root->count += 1;
        }
        return root;
    }

    Node* searchThree(Node* root, const T& data) {
        if (root == nullptr || root->data == data) {
            return root;
        }
        if (data < root->data) {
            return searchThree(root->left, data);
        }
        return searchThree(root->right, data);
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& data) {
        root = addN(root, data);
    }
    int depth() {
        return depthThree(root) - 1;
    }
    int search(const T& data) {
        Node* curr = searchThree(root, data);
        if (curr == nullptr) {
            return 0;
        } else {
            return curr->count;
        }
    }
};
#endif  // INCLUDE_BST_H_
