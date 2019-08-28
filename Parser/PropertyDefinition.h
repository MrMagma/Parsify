//
// Created by joshu on 8/27/2019.
//

#ifndef PARSIFY_PROPERTYDEFINITION_H
#define PARSIFY_PROPERTYDEFINITION_H


#include <string>
#include "../Tokenizer/TokenStream.h"

class PropertyDefinition {
public:
    PropertyDefinition(std::string type, std::string name);
    std::string type;
    std::string name;
    static PropertyDefinition* attemptParse(TokenStream& ts);
};


#endif //PARSIFY_PROPERTYDEFINITION_H
