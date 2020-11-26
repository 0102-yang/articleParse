/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 09:13:16
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 13:29:50
 * @FilePath: /articleParse/src/parser.cpp
 */
#include "parser.h"

#include <sstream>
#include <string>

#include "global.h"

Parser* Parser::parser = nullptr;

WordOccurency Parser::parse(const Article& article) {
    WordOccurency result;

    for (const auto& line : article) {
        // Get parsed str.
        std::string transferedLine =
            this->transferStrToWithoutUpperAndPunct(line.second);

        // Generate wordOccurency.
        std::istringstream iss(transferedLine);
        std::string temp;
        while (iss >> temp) {
            result[temp].insert(line.first);
        }
    }

    return result;
}

std::string Parser::transferStrToWithoutUpperAndPunct(const std::string& str) {
    std::string result = str;

    for (auto& c : result) {
        if (isupper(c))
            c = tolower(c);
        else if ((ispunct(c) && c != '-') || isdigit(c))
            c = ' ';
    }

    return result;
}