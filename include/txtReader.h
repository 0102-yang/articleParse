/*
 * @Author: Yang
 * @Copyright: Yang
 * @Date: 2020-11-26 08:36:26
 * @LastEditors: Yang
 * @LastEditTime: 2020-11-26 12:55:46
 * @FilePath: /articleParse/include/txtReader.h
 */
#ifndef _TXT_READER_
#define _TXT_READER_

#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "global.h"

class TxtReader {
   public:
    TxtReader(const TxtReader&) = delete;

    static TxtReader* getInstance() {
        // note: It need to be fixed if the program support multi-thread
        // running. Only fit for single thread model.
        if (instance == nullptr) {
            instance = new TxtReader;
        }

        return instance;
    }

    Article read(std::ifstream& ifs);

   private:
    TxtReader() = default;

   private:
    static TxtReader* instance;
};

#endif  // _TXT_READER_