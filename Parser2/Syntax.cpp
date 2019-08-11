//
// Created by Joshua on 8/10/2019.
//

#include "Syntax.h"

Syntax::Syntax(std::vector<Rule *> &rules) {
    this->rules = rules;
}

Syntax* Syntax::attemptParse(FileReadInterface &input) {
    std::vector<Rule*> rules = {};
    Rule* rule = nullptr;
    while ((rule = Rule::attemptParse(input)) != nullptr) rules.push_back(rule);
    return new Syntax(rules);
}
