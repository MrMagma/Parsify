//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_MATCHER_H
#define PARSIFY_MATCHER_H


#include <vector>
#include "Checker.h"
#include "Condition.h"

class Matcher : public Condition {
public:
    std::vector<Checker*> checks = {};
};


#endif //PARSIFY_MATCHER_H
