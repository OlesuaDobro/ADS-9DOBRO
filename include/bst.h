// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "BST.h"

BST<std::string> maketree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка открытия файла");
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content = buffer.str();
    std::regex wordregex("[a-zA-Z]+");
    std::smatch match;
    while (std::regex_search(content, match, wordregex)) {
        std::string word = match.str();
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        tree.insert(word);
        content = match.suffix();
    }
    return tree;
}
#endif  // INCLUDE_BST_H_
