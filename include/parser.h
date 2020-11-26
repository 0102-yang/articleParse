/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 09:13:05
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 13:25:22
 * @FilePath: /articleParse/include/parser.h
 */
#ifndef _PARSER_H_
#define _PARSER_H_
#include "global.h"

class Parser {
    // todo: The class Parser need to be a singleton class.
   public:
    Parser(const Parser&) = delete;

    WordOccurency parse(const Article& article);

    static Parser* getInstance() {
        if (parser == nullptr) {
            parser = new Parser;
        }

        return parser;
    }

    static std::string transferStrToWithoutUpperAndPunct(
        const std::string& str);

   private:
    Parser() = default;

    static Parser* parser;
};
#endif  // _PARSER_H_