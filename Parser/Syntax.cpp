//
// Created by Joshua on 8/11/2019.
//

#include "Syntax.h"
#include "TokenDefinition.h"

Syntax::Syntax(std::vector<Definition *> definitions) {
    this->definitions = definitions;
}

Syntax *Syntax::attemptParse(TokenStream &ts) {
    std::vector<Definition*> definitions = {};
    Definition* temp = nullptr;

    while ((temp = TokenDefinition::attemptParse(ts)) != nullptr) definitions.push_back(temp);

    return new Syntax(definitions);
}
