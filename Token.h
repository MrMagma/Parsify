//
// Created by Joshua on 8/8/2019.
//

#ifndef PARSIFY_TOKEN_H
#define PARSIFY_TOKEN_H

#define TOKENIZER_TOKEN_TOKENTYPES Identifier, Regex, End

#include <string>

enum class TokenType {
    TOKENIZER_TOKEN_TOKENTYPES
};

class Token {
public:
    Token(TokenType type, std::string content) {
        this->type = type;
        this->content = std::move(content);
    }
    TokenType type;
    std::string content;
};


#endif //PARSIFY_TOKEN_H
