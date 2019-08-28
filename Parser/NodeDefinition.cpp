//
// Created by joshu on 8/22/2019.
//

#include "NodeDefinition.h"
#include "PropertyDefinition.h"

NodeDefinition::NodeDefinition(std::string name, std::vector<PropertyDefinition *> properties) : Definition(name) {
    this->properties = properties;
}

Definition *NodeDefinition::attemptParse(TokenStream &ts) {
    std::string name;
    std::vector<PropertyDefinition*> properties;
    ts.markCheckpoint();

    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }

    if (ts.peek()->type == TokenType::identifier && ts.peek()->content == "Node") {
        ts.get();
    } else {
        ts.goBack();
        return nullptr;
    }

    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }

    if (ts.peek()->type == TokenType::identifier) {
        name = ts.get()->content;
    } else {
        ts.goBack();
        return nullptr;
    }

    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }

    if (ts.peek()->type == TokenType::openBlock) {
        ts.get();
    } else {
        ts.goBack();
        return nullptr;
    }

    // TODO Do shit
    PropertyDefinition* temp;
    while ((temp = PropertyDefinition::attemptParse(ts)) != nullptr) {
        properties.push_back(temp);
    }

    if (ts.peek()->type == TokenType::whitespace) {
        ts.get();
    }

    if (ts.peek()->type == TokenType::closeBlock) {
        ts.get();
    } else {
        for (PropertyDefinition* p : properties) delete p;
        ts.goBack();
        return nullptr;
    }

    ts.forgetCheckpoint();
    return new NodeDefinition(name, properties);
}

