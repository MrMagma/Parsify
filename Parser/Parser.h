//
// Created by Joshua on 8/9/2019.
//

#ifndef PARSIFY_PARSER_H
#define PARSIFY_PARSER_H


#include <string>
#include "../Tokenizer/TokenStream.h"
#include "SyntaxDefinition.h"

class Parser {
public:
    explicit Parser(const std::string& inputPath);
    SyntaxDefinition* parse();
private:
    TokenStream tokenStream;
};


#endif //PARSIFY_PARSER_H
