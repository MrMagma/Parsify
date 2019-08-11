//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_SET_H
#define PARSIFY_SET_H


#include <string>
#include <vector>
#include "FileReadInterface.h"

class Set {
public:
    Set(std::string flag, std::vector<std::string>& elements);
    static Set* attemptParse(FileReadInterface& input);
    std::string flag;
    std::vector<std::string> elements;
};


#endif //PARSIFY_SET_H
