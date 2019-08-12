//
// Created by Joshua on 8/9/2019.
//

#ifndef PARSIFY_TRANSLATOR_H
#define PARSIFY_TRANSLATOR_H


#include <string>

class Translator {
public:
    Translator(const std::string& inputPath, const std::string& outputPath);
    std::string tokenHeaderStubPath = "Token.h";
    std::string tokenStreamHeaderStubPath = "TokenStream.h";
    std::string tokenStreamSourceStubPath = "TokenStream.cpp";
    void translate();
private:
    static std::string translateRegex(const std::string& regex);
    std::string outputPath;
};


#endif //PARSIFY_TRANSLATOR_H
