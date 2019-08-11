//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_STRING_H
#define PARSIFY_STRING_H


#include <string>
#include "FileReadInterface.h"

class String {
public:
    explicit String(std::string content);
    static String* attemptParse(FileReadInterface& input);
    std::string content;
};


#endif //PARSIFY_STRING_H
