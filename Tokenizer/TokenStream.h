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
    unsigned long long tellg();
    void seekg(unsigned long long pos);
    TokenStream& operator>>(Token*&);
    Token* get();
    Token* peek();
private:
    void init();
    Token* next = nullptr;
    unsigned long long getPointer = 0;
    std::string buffer;
    std::vector<Matcher> matchers;
    std::ifstream inputFile;
};


#endif //PARSIFY_TOKENSTREAM_H
