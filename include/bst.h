// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <string>
#include <sstream>
#include "bst.h"
template <typename T>

    class BST {

        public:
BST() {
        root = nullptr;
}
     struct Node {
        T data;
        int count;
        Node* left;
        Node* right;
        Node(const T& data) {
            data = data;
            count = 1;
            left = nullptr;
            right = nullptr;
        }
                  };
    void insert(const t& value) {
        root = add(root, value);
    }
    int depth() const {
        return depthoftree(root) - 1;
    }
    int search(const t& value) const {
        return wordsearch(root, value);
    }

 private:
node* add(node* node, const t& value) {
    if (node == nullptr) {
        return new node(value);
    }
    node* current = node;
    node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (current->data > value) {
            current = current->left;
        } else if (current->data < value) {
            current = current->right;
        } else {
            current->count++;
            return node;
        }
    }
    if (parent->data > value) {
        parent->left = new node(value);
    } else {
        parent->right = new node(value);
    }
    return node;
}
int depthoftree(node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + std::max(depthoftree(node->left), depthoftree(node->right));
}
int wordsearch(node* node, const t& value) const {
    while (node != nullptr) {
        if (node->data == value) {
            return node->count;
        } else if (node->data < value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return 0;
}
};

#endif  // INCLUDE_BST_H_
