/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 09:11:30
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 12:46:35
 * @FilePath: /articleParse/include/global.h
 */
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <map>
#include <string>
#include <tuple>
#include <unordered_set>

using Line = unsigned;

using Article = std::map<Line, std::string>;

using WordOccurency = std::map<std::string, std::unordered_set<Line>>;

using ArticleCollection =
    std::map<std::string, std::tuple<Article, WordOccurency>>;

#endif  // _GLOBAL_H_