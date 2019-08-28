//
// Created by Joshua on 8/11/2019.
//

#include "Syntax.h"
#include "TokenDefinition.h"
#include "NodeDefinition.h"

Syntax::Syntax(std::vector<Definition *> definitions) {
    this->definitions = definitions;
}

Syntax *Syntax::attemptParse(TokenStream &ts) {
    std::vector<Definition*> definitions = {};
    Definition* temp = nullptr;

    do {
        temp = TokenDefinition::attemptParse(ts);
        if (temp != nullptr) definitions.push_back(temp);
        else {
            temp = NodeDefinition::attemptParse(ts);
            if (temp != nullptr) definitions.push_back(temp);
        }
    } while (temp != nullptr);

    return new Syntax(definitions);
}
