//
// Created by Joshua on 8/9/2019.
//

#ifndef PARSIFY_SYNTAXDEFINITION_H
#define PARSIFY_SYNTAXDEFINITION_H


#include <vector>
#include "TokenDefinition.h"

class SyntaxDefinition {
public:
    std::vector<TokenDefinition*> declarations;
};


#endif //PARSIFY_SYNTAXDEFINITION_H
