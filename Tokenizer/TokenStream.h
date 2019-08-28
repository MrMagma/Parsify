#ifndef PARSIFY_TOKENSTREAM_H
#define PARSIFY_TOKENSTREAM_H

#define TOKENSTREAM_BUFFER_SIZE 2000

#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include "Token.h"

struct Matcher {
    const std::regex pattern;
    const TokenType type;
};

class TokenStream {
public:
    explicit TokenStream(const std::string& inputPath);
    void markCheckpoint();
    void goBack();
    void forgetCheckpoint();
    TokenStream& operator>>(Token*&);
    Token* get();
    Token* peek();
private:
    void defineTokens();
    Token* next = nullptr;
    std::vector<std::ifstream::pos_type> checkpoints = {};
    std::ifstream::pos_type getPointer = 0;
    std::string buffer;
    std::vector<Matcher> matchers;
    std::string inputFilePath;
    std::ifstream inputFile;
};


#endif //PARSIFY_TOKENSTREAM_H
