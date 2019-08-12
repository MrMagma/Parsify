//
// Created by Joshua on 8/9/2019.
//

#ifndef PARSIFY_TRANSLATOR_H
#define PARSIFY_TRANSLATOR_H


#include <string>

class Translator {
public:
    std::string inputPath = "";
    std::string tokenDefinitionPath = "";
    std::string tokenStreamHeaderPath = "";
    std::string tokenTypePath = "";
    std::string endTokenName = "End";
    void translate();
private:
    static std::string translateRegex(const std::string& regex);
};


#endif //PARSIFY_TRANSLATOR_H
