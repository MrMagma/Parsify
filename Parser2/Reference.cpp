//
// Created by Joshua on 8/10/2019.
//

#include "Reference.h"
#include "BaseChecks.h"

#include <utility>
#include <iostream>

Reference::Reference(std::string name) {
    this->name = std::move(name);
}

Reference *Reference::attemptParse(FileReadInterface &input) {
    int pos = input.getPointer();
    std::string name;
    std::string whitespace;
    readWhitespace(input, whitespace);
    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')) {
        name += input[0];
        input.movePointer(1);
        while ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= '0' && input[0] <= '9')) {
            name += input[0];
            input.movePointer(1);
        }
        readWhitespace(input, whitespace);
        return new Reference(name);
    } else {
        std::cerr << "Reference failed 1" << std::endl;
        return nullptr;
    }
}
