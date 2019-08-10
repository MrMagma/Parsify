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
