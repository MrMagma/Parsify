#include <regex>
#include <iostream>
#include "TokenStream.h"

TokenStream::TokenStream(const std::string &inputPath) {
    inputFilePath = inputPath;
    inputFile.open(inputPath);
    if (!inputFile.is_open()) std::cerr << "TokenStream unable to open file \"" << inputPath << "\"" << std::endl;
    defineTokens();
}

TokenStream& TokenStream::operator>>(Token*& outputLoc) {
    outputLoc = get();
    return *this;
}

Token *TokenStream::get() {
    peek();
    auto* out = new Token(next->type, next->content);
    next = nullptr;
    return out;
}

Token *TokenStream::peek() {
    if (next == nullptr) {
        while (buffer.length() < TOKENSTREAM_BUFFER_SIZE && inputFile.peek() != EOF) buffer += char(inputFile.get());
        std::smatch sm;
        for (const Matcher& m : matchers) {
            std::regex_search(buffer, sm, m.pattern);
            if (sm.length() > 0 && sm.position(0) == 0) {
                if (sm.size() == 1) next = new Token(m.type, sm[0]);
                else next = new Token(m.type, sm[1]);
                getPointer += sm[0].length();
                buffer = buffer.substr(sm[0].length(), buffer.length() - sm[0].length());
                return next;
            }
        }
        return next = new Token(TokenType::End, "");
    }
    return next;
}

void TokenStream::markCheckpoint() {
//    auto checkpoint = inputFile.tellg();
//    if (checkpoint < 0) {
//
//    } else {
//        checkpoints.push_back(checkpoint);
//    }
    checkpoints.push_back(getPointer);
}

void TokenStream::goBack() {
    buffer = "";
    next = nullptr;
    inputFile.close();
    inputFile.open(inputFilePath);
    if (!inputFile.is_open()) std::cerr << "TokenStream unable to open file \"" << inputFilePath << "\"" << std::endl;
    auto checkpointLoc = checkpoints.end();
    checkpointLoc--;
    inputFile.seekg(*checkpointLoc);
    checkpoints.pop_back();
}

void TokenStream::forgetCheckpoint() {
    checkpoints.pop_back();
}
