#include <regex>
#include <iostream>
#include "TokenStream.h"

TokenStream::TokenStream(const std::string &inputPath) {
    inputFile.open(inputPath);
    if (!inputFile.is_open()) std::cerr << "TokenStream unable to open file \"" << inputPath << "\"" << std::endl;
    init();
}

TokenStream& TokenStream::operator>>(Token*& outputLoc) {
    outputLoc = get();
    return *this;
}

unsigned long long TokenStream::tellg() {
    return inputFile.tellg();
}

void TokenStream::seekg(unsigned long long pos) {
    inputFile.seekg(pos);
    if (pos < getPointer || pos >= getPointer + buffer.length()) {
        buffer = "";
    } else {
        buffer = buffer.substr(pos - getPointer, buffer.length() - pos + getPointer);
    }
    getPointer = pos;
}

Token *TokenStream::get() {
    peek();
    auto* out = new Token(next->type, next->content);
    next = nullptr;
    return out;
}

Token *TokenStream::peek() {
    if (next == nullptr) {
        while (buffer.length() < TOKENSTREAM_BUFFER_SIZE && !inputFile.eof()) buffer += char(inputFile.get());
        getPointer = inputFile.tellg();
        std::smatch sm;
        for (const Matcher& m : matchers) {
            std::regex_search(buffer, sm, m.pattern);
            if (sm.length() > 0 && sm.position(0) == 0) {
                if (sm.length() == 1) next = new Token(m.type, sm[1]);
                next = new Token(m.type, sm[0]);
                buffer = buffer.substr(sm[0].length(), buffer.length() - sm[0].length());
                return next;
            }
        }
        return next = new Token(TokenType::End, "");
    }
    return next;
}