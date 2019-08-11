//
// Created by Joshua on 8/10/2019.
//

#include "Set.h"

#include <utility>
#include <iostream>
#include "BaseChecks.h"

Set::Set(std::string flag, std::vector<std::string> &elements) {
    this->flag = std::move(flag);
    this->elements = elements;
}

Set *Set::attemptParse(FileReadInterface &input) {
    int pos = input.getPointer();
    std::string whitespace;
    readWhitespace(input, whitespace);
    if (input[0] == '[') {
        input.movePointer(1);
        std::string flag;
        if (input[0] == '^') {
            flag += input[0];
            input.movePointer(1);
        }
        std::vector<std::string> elements = {};
        std::string element;
        while (readCharacter(input, element)) {
            if (element == "]") break;

            if (input[0] == '-') {
                element += "-";
                input.movePointer(1);
                if (readCharacter(input, element)) {
                    elements.push_back(element);
                    element = "";
                } else {
                    input.setPointer(pos);
                    std::cerr << "Set failed 1" << std::endl;
                    return nullptr;
                }
            } else {
                elements.push_back(element);
                element = "";
            }
        }

        if (element == "]") {
            readWhitespace(input, whitespace);
            return new Set(flag, elements);
        } else {
            input.setPointer(pos);
            std::cerr << "Set failed 2" << std::endl;
            return nullptr;
        }
    } else {
        std::cerr << "Set failed 3" << std::endl;
        return nullptr;
    }
}
