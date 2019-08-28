//
// Created by joshu on 8/22/2019.
//

#ifndef PARSIFY_NODEDEFINITION_H
#define PARSIFY_NODEDEFINITION_H


#include "../Tokenizer/TokenStream.h"
#include "Definition.h"
#include "PropertyDefinition.h"

class NodeDefinition : public Definition {
public:
    NodeDefinition(std::string name, std::vector<PropertyDefinition*> properties);
    static Definition* attemptParse(TokenStream& ts);
    std::vector<PropertyDefinition*> properties;
};


#endif //PARSIFY_NODEDEFINITION_H
