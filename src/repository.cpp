/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 10:38:18
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 13:28:59
 * @FilePath: /articleParse/src/repository.cpp
 */
#include "repository.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

#include "global.h"
#include "parser.h"
#include "txtReader.h"

void Repository::append(const std::string& filename) {
    if (repository.find(filename) != repository.cend()) {
        throw std::logic_error(
            "Can not append! This file is already in this repository.");
    }

    std::ifstream ifs(filename);

    try {
        TxtReader* ir = TxtReader::getInstance();

        Parser* p = Parser::getInstance();

        auto&& originalArticle = ir->read(ifs);

        auto&& wordOccurency = p->parse(originalArticle);

        repository.insert(
            {filename, make_tuple(originalArticle, wordOccurency)});

    } catch (std::logic_error& e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Can not append! Can not open this file." << std::endl;
    }
}

void Repository::queryFile(const std::string& filename,
                           const std::string& word) {
    auto itr = repository.find(filename);
    if (itr == repository.cend()) {
        throw std::logic_error("This repository does not have this file.");
    }

    auto& originalArticle = std::get<0>(itr->second);
    auto& wordOccurency = std::get<1>(itr->second);

    auto& lines = wordOccurency.at(word);
    std::ostringstream os;
    for (auto l : lines) {
        os << "(line " << l << ") " << originalArticle[l] << '\n';
    }

    std::cout << os.str() << std::endl;
}