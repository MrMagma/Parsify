#ifndef PARSIFY_TOKENSTREAM_H
#define PARSIFY_TOKENSTREAM_H

#define TOKENSTREAM_BUFFER_SIZE 2000

#include <string>
#include <fstream>
#include "Token.h"

class TokenStream {
public:
    explicit TokenStream(const std::string& inputPath);
    TokenStream& operator>>(Token*&);
private:
    bool matchToken(const std::string& pattern, Token*& outputLoc, TokenType type, bool ignore);
    std::string buffer;
    std::ifstream inputFile;
};


#endif //PARSIFY_TOKENSTREAM_H
