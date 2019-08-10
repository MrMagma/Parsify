//
// Created by Joshua on 8/9/2019.
//

#include "Parser.h"

Parser::Parser(const std::string& inputPath) : tokenStream(inputPath) {

}

SyntaxDefinition *Parser::parse() {
    auto* root = new SyntaxDefinition;
    Token* token = nullptr;
    do {
        delete token;
        tokenStream >> token;
        if (token->type != TokenType::Identifier) break; // TODO Throw error
        if (token->content == "ignore") {
            delete token;
            tokenStream >> token;
            if (token->type != TokenType::Regex) break; // TODO Throw error
            // TODO Ignore declarations need their own class, but I'm too lazy to make one right now
            root->declarations.push_back(new TokenDefinition("ignore", token->content));
        } else if (token->content == "Token") {
            delete token;
            tokenStream >> token;
            if (token->type != TokenType::Identifier) break; // TODO Throw error
            std::string name = token->content;
            delete token;
            tokenStream >> token;
            if (token->type != TokenType::Identifier || token->content != "is") break; // TODO Throw error
            delete token;
            tokenStream >> token;
            if (token->type != TokenType::Regex) break; // TODO Throw error
            root->declarations.push_back(new TokenDefinition(name, token->content));
        } else {
            break; // TODO Throw error
        }
    } while (token->type != TokenType::End);
    return root;
}
