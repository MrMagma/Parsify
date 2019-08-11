//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_REPEATER_H
#define PARSIFY_REPEATER_H


#include <string>
#include "FileReadInterface.h"

class Repeater {
public:
    explicit Repeater(std::string content);
    static Repeater* attemptParse(FileReadInterface& input);
    std::string content;
};


#endif //PARSIFY_REPEATER_H
