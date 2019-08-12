#ifndef TOKEN_TYPE_HEADER
#define TOKEN_TYPE_HEADER

enum class TokenType {
    End,
    arrow,
    closeArray,
    closeBlock,
    closeParen,
    identifier,
    number,
    openArray,
    openBlock,
    openParen,
    regex,
    whitespace
};

#endif