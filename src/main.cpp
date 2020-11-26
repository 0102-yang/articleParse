/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 12:48:15
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 13:30:21
 * @FilePath: /articleParse/src/main.cpp
 */
#include <string>

#include "parser.h"
#include "repository.h"
#include "txtReader.h"

int main(int argc, char const *argv[]) {
    Repository r;
    const std::string filename = "../mapple.txt";
    r.append(filename);
    r.queryFile(filename, std::string("test"));

    return 0;
}