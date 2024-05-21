// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

struct Node {
    std::string key;
    int freq;
    Node* left;
    Node* right;

    Node(const std::string& word) {
        key = word;
        freq = 1;
        left = nullptr;
        right = nullptr;
    }
};
class BST {
private:
    Node* root;
    Node* insert(Node* node, const std::string& word) {
        if (node == nullptr) {
            node = new Node(word);
        }
        else if (word < node->key) {
            node->left = insert(node->left, word);
        }
        else if (word > node->key) {
            node->right = insert(node->right, word);
        }
        else {
            node->freq++;
        }
        return node;
    }
    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    BST() {
        root = nullptr;
    }
    ~BST() {
        destroy(root);
    }
    void insert(const std::string& word) {
        root = insert(root, word);
    }
    void maketree(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "file error!" << std::endl;
            return;
        }
        std::map<std::string, int> wordFreq;
        std::string word;
        char ch;
        while (file.get(ch)) {
            ch = std::tolower(ch);
            if (std::isalpha(ch)) {
                word += ch;
            }
            else if (!word.empty()) {
                wordFreq[word]++;
                word = "";
            }
        }
        if (!word.empty()) {
            wordFreq[word]++;
        }
        for (const auto& pair : wordFreq) {
            insert(pair.first);
        }
        file.close();
    }
};
#endif  // INCLUDE_BST_H_
