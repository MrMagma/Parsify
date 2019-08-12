#ifndef TOKENIZER_TOKEN_H
#define TOKENIZER_TOKEN_H
#define TOKENIZER_TOKEN_TOKENTYPES number, whitespace, identifier, regex, openBlock, closeBlock, openArray, closeArray, openParen, closeParen, arrow, End
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

#endif
