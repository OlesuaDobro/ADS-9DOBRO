#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <map>

template<typename T>
struct BSTNode {
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode(T val) : data(val), left(nullptr), right(nullptr) {}
};
template<typename T>
class BST {
public:
    BST() : root(nullptr) {}
    void Insert(T val) {
        root = InsertHelper(root, val);
    }
    void InOrderTraversal(std::map<T, int>& wordCount) {
        InOrderTraversalHelper(root, wordCount);
    }
private:
    BSTNode<T>* root;
    BSTNode<T>* InsertHelper(BSTNode<T>* node, T val) {
        if (node == nullptr) {
            return new BSTNode<T>(val);
        }
        if (val < node->data) {
            node->left = InsertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = InsertHelper(node->right, val);
        }
        return node;
    }
    void InOrderTraversalHelper(BSTNode<T>* node, std::map<T, int>& wordCount) {
        if (node != nullptr) {
            InOrderTraversalHelper(node->left, wordCount);
            wordCount[node->data]++;
            InOrderTraversalHelper(node->right, wordCount);
        }
    }
};
BST<std::string> maketree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return BST<std::string>();
    }
    std::map<std::string, int> wordCount;
    std::string word;
    while (file >> word) {
        std::string cleanedWord;
        for (char& c : word) {
            if (isalpha(c)) {
                cleanedWord += tolower(c);
            }
        }
        wordCount[cleanedWord]++;
    }
    file.close();
    BST<std::string> tree;
    for (const auto& pair : wordCount) {
        tree.Insert(pair.first);
    }
    return tree;
}
int main() {
    const char* filename = "war_peace.txt";
    BST<std::string> tree = maketree(filename);
    std::map<std::string, int> wordCount;
    tree.InOrderTraversal(wordCount);
    for (const auto& pair : wordCount) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
    return 0;
}
