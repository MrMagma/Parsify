#include "TokenStream.h"

void TokenStream::defineTokens() {
    matchers.push_back(Matcher{std::regex("[1-9][0-9]*"), TokenType::number});
    matchers.push_back(Matcher{std::regex("\\s+"), TokenType::whitespace});
    matchers.push_back(Matcher{std::regex("[a-zA-Z][a-zA-Z0-9]*"), TokenType::identifier});
    matchers.push_back(Matcher{std::regex("\\/([^]*?[^\\\\])\\/"), TokenType::regex});
    matchers.push_back(Matcher{std::regex("\\{"), TokenType::openBlock});
    matchers.push_back(Matcher{std::regex("\\}"), TokenType::closeBlock});
    matchers.push_back(Matcher{std::regex("\\["), TokenType::openArray});
    matchers.push_back(Matcher{std::regex("\\]"), TokenType::closeArray});
    matchers.push_back(Matcher{std::regex("\\("), TokenType::openParen});
    matchers.push_back(Matcher{std::regex("\\)"), TokenType::closeParen});
    matchers.push_back(Matcher{std::regex("\\-\\>"), TokenType::arrow});
}