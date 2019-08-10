//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_CHECKER_H
#define PARSIFY_CHECKER_H


#include <string>
#include "Repeater.h"
#include "Condition.h"

class Checker {
public:
    std::string name = "";
    Condition* condition = nullptr;
    Repeater* repeater = nullptr;
};


#endif //PARSIFY_CHECKER_H
