// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return tree;
    }
    std::string word;
    while (file) {
        char str = file.get();
        if (isalpha(str)) {
            str = tolower(str);
            word += str;
        } else if (!(word.empty())) {
            tree.add(word);
            word = "";
        }
    }
    return tree;
}
