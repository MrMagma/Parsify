//
// Created by Joshua on 8/10/2019.
//

#include "Rule.h"
#include "BaseChecks.h"

#include <utility>
#include <iostream>

Rule::Rule(std::string name, Sequence* sequence) {
    this->name = std::move(name);
    this->sequence = sequence;
}

Rule *Rule::attemptParse(FileReadInterface &input) {
    int pos = input.getPointer();
    std::string name;
    Sequence* sequence = nullptr;
    std::string whitespace;

    readWhitespace(input, whitespace);

    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')) {
        name += input[0];
        input.movePointer(1);
        while ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= '0' && input[0] <= '9')) {
            name += input[0];
            input.movePointer(1);
        }
    }

    readWhitespace(input, whitespace);

    Matcher* matcher = nullptr;
    if (input[0] == '{') {
        input.movePointer(1);
        readWhitespace(input, whitespace);
        if ((sequence = Sequence::attemptParse(input)) != nullptr) {
            readWhitespace(input, whitespace);
            if (input[0] == '}') {
                input.movePointer(1);
                readWhitespace(input, whitespace);
                return new Rule(name, sequence);
            } else {
                delete sequence;
                input.setPointer(pos);
                std::cerr << "Rule failed 1" << std::endl;
                return nullptr;
            }
        } else {
            input.setPointer(pos);
            std::cerr << "Rule failed 2" << std::endl;
            return nullptr;
        }
    } else {
        input.setPointer(pos);
        std::cerr << "Rule failed 3" << std::endl;
        return nullptr;
    }
}
