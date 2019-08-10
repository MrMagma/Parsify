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