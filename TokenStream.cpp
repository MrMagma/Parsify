//
// Created by Joshua on 8/8/2019.
//

#include <regex>
#include "TokenStream.h"

TokenStream::TokenStream(const std::string& inputPath) {
    inputFile.open(inputPath);
    if (!inputFile.good()) return; // TODO Throw error
}

bool TokenStream::matchToken(const std::string& pattern, Token*& outputLoc, TokenType type, bool ignore) {
    std::smatch sm;
    std::regex matcher(pattern);
    std::regex_search(buffer, sm, matcher);
    if (sm.length() > 0 && sm.position(0) == 0) {
        if (ignore) {
            buffer = buffer.substr(sm[0].length(), buffer.length() - sm[0].length());
            *this >> outputLoc;
            return true;
        } else {
            if (sm.length() == 1) outputLoc = new Token(type, sm[0]);
            else outputLoc = new Token(type, sm[1]);
            buffer = buffer.substr(sm[0].length(), buffer.length() - sm[0].length());
            return true;
        }
    }
    return false;
}

TokenStream& TokenStream::operator>>(Token*& outputLoc) {
    while (buffer.length() < TOKENSTREAM_BUFFER_SIZE && inputFile.peek() != EOF) buffer += char(inputFile.get());

    if (matchToken("([A-Za-z]+)", outputLoc, TokenType::Identifier, false)) {
        return *this;
    }

    if (matchToken("/([^]*?[^\\\\])/", outputLoc, TokenType::Regex, false)) {
        return *this;
    }

    if (matchToken("\\s", outputLoc, TokenType::End, true)) {
        return *this;
    }

    // TODO Indicate error
    outputLoc = new Token(TokenType::End, "");
    return *this;
}
