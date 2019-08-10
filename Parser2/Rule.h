//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_RULE_H
#define PARSIFY_RULE_H


#include <vector>
#include "Matcher.h"

class Rule {
public:
    std::vector<Matcher*> definition = {};
};


#endif //PARSIFY_RULE_H
