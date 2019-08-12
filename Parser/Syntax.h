//
// Created by Joshua on 8/11/2019.
//

#ifndef PARSIFY_SYNTAX_H
#define PARSIFY_SYNTAX_H


#include <vector>
#include "Definition.h"
#include "../Tokenizer/TokenStream.h"

class Syntax {
public:
    explicit Syntax(std::vector<Definition*> definitions);
    static Syntax* attemptParse(TokenStream& ts);
    std::vector<Definition*> definitions;
};


#endif //PARSIFY_SYNTAX_H
