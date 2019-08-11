//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_MATCHER_H
#define PARSIFY_MATCHER_H


#include <vector>
#include "Checker.h"

class Checker;

class Matcher {
public:
    Matcher(std::vector<Checker*>& checks);
    std::vector<Checker*> checks = {};
    static Matcher* attemptParse(FileReadInterface& input);
};


#endif //PARSIFY_MATCHER_H
