/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 08:36:42
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 13:00:29
 * @FilePath: /articleParse/src/txtReader.cpp
 */
#include "txtReader.h"

TxtReader* TxtReader::instance = nullptr;

Article TxtReader::read(std::ifstream& ifs) {
    if (!ifs.is_open())
        throw std::logic_error("Can not read data from this file.");

    Article result;
    std::string singleLine;
    Line line = 0;

    // Read data from file.
    while (getline(ifs, singleLine)) {
        result.insert({++line, singleLine});
    }

    return result;
}