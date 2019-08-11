//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_RULE_H
#define PARSIFY_RULE_H


#include <vector>
#include "Matcher.h"
#include "Sequence.h"

class Rule {
public:
    Rule(std::string name, Sequence* sequence);
    std::string name;
    Sequence* sequence;
    static Rule* attemptParse(FileReadInterface& input);
};


#endif //PARSIFY_RULE_H
