#ifndef TOKENIZER_TOKEN_H
#define TOKENIZER_TOKEN_H


#include <string>
#include "TokenType.h"

class Token {
public:
    Token(TokenType type, std::string content) {
        this->type = type;
        this->content = std::move(content);
    }
    TokenType type;
    std::string content;
};

#endif
