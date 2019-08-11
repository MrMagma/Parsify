//
// Created by Joshua on 8/10/2019.
//

#include "String.h"
#include "BaseChecks.h"

#include <utility>
#include <iostream>

String::String(std::string content) {
    this->content = std::move(content);
}

String *String::attemptParse(FileReadInterface &input) {
    int pos = input.getPointer();
    std::string whitespace;
    readWhitespace(input, whitespace);
    if (input[0] == '\"') {
        input.movePointer(1);
        std::string content;
        while (readCharacter(input, content, '"'));
        if (input[0] == '\"') {
            input.movePointer(1);
            readWhitespace(input, whitespace);
            return new String(content);
        } else {
            input.setPointer(pos);
            std::cerr << "String failed 1" << std::endl;
            return nullptr;
        }
    } else {
        std::cerr << "String failed 2" << std::endl;
        return nullptr;
    }
}
