//
// Created by Joshua on 8/11/2019.
//

#include "TokenDefinition.h"

TokenDefinition::TokenDefinition(std::string name, std::string expression) : Definition(name) {
    this->expression = expression;
}

Definition *TokenDefinition::attemptParse(TokenStream& ts) {
    std::string name;
    std::string expression;
    auto start = ts.tellg();
    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }
    if (ts.peek()->type == TokenType::identifier && ts.peek()->content == "Token") {
        ts.get();
    } else {
        ts.seekg(start);
        return nullptr;
    }
    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }
    if (ts.peek()->type == TokenType::identifier) {
        name = ts.peek()->content;
        ts.get();
    } else {
        ts.seekg(start);
        return nullptr;
    }
    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }
    if (ts.peek()->type == TokenType::regex) {
        expression = ts.peek()->content;
        ts.get();
    } else {
        ts.seekg(start);
        return nullptr;
    }
    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }
    return new TokenDefinition(name, expression);
}
