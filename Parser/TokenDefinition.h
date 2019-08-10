//
// Created by Joshua on 8/9/2019.
//

#ifndef PARSIFY_TOKENDEFINITION_H
#define PARSIFY_TOKENDEFINITION_H


#include <string>

class TokenDefinition {
public:
    TokenDefinition(std::string name, std::string pattern);
    std::string name;
    std::string pattern;
};


#endif //PARSIFY_TOKENDEFINITION_H
