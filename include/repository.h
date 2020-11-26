/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 10:38:08
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 12:51:58
 * @FilePath: /articleParse/include/repository.h
 */
#ifndef _QUERY_H_
#define _QUERY_H_
#include <string>

#include "global.h"
class Repository {
   public:
    Repository() = default;

    /** Append specified article to this storage from its filename.
     * @param filename The filename of the article.
     */
    void append(const std::string& filename);

    /** Remove all the data in this repository.
     */
    void reset() { repository.clear(); }

    void queryFile(const std::string& filename, const std::string& word);

   private:
    ArticleCollection repository;
};
#endif  // _QUERY_H_