//
// Created by joshu on 8/27/2019.
//

#include "PropertyDefinition.h"

PropertyDefinition::PropertyDefinition(std::string type, std::string name) {
    this->type = type;
    this->name = name;
}

PropertyDefinition *PropertyDefinition::attemptParse(TokenStream &ts) {
    ts.markCheckpoint();
    std::string type;
    std::string name;

    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }

    if (ts.peek()->type == TokenType::identifier) {
        type = ts.get()->content;
    } else {
        ts.goBack();
        return nullptr;
    }

    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }

    if (ts.peek()->type == TokenType::identifier) {
        name = ts.get()->content;
    } else {
        ts.goBack();
        return nullptr;
    }

    ts.forgetCheckpoint();
    return new PropertyDefinition(type, name);
}
