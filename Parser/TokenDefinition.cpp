//
// Created by Joshua on 8/9/2019.
//

#include "TokenDefinition.h"

#include <utility>

TokenDefinition::TokenDefinition(std::string name, std::string pattern) {
    this->name = std::move(name);
    this->pattern = std::move(pattern);
}
