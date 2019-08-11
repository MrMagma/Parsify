//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_SYNTAX_H
#define PARSIFY_SYNTAX_H


#include <vector>
#include "Rule.h"

class Syntax {
public:
    explicit Syntax(std::vector<Rule*>& rules);
    std::vector<Rule*> rules = {};
    static Syntax* attemptParse(FileReadInterface& input);
};


#endif //PARSIFY_SYNTAX_H
