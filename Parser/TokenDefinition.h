//
// Created by Joshua on 8/11/2019.
//

#ifndef PARSIFY_TOKENDEFINITION_H
#define PARSIFY_TOKENDEFINITION_H


#include <string>
#include "Definition.h"
#include "../Tokenizer/TokenStream.h"

class TokenDefinition : virtual public Definition {
public:
    TokenDefinition(std::string name, std::string expression);
    std::string expression;
    static Definition* attemptParse(TokenStream&);
};


#endif //PARSIFY_TOKENDEFINITION_H
