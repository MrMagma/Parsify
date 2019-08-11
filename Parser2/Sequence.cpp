//
// Created by Joshua on 8/11/2019.
//

#include <iostream>
#include "Sequence.h"
#include "BaseChecks.h"

Sequence::Sequence(std::vector<Matcher *> &definition) {
    this->definition = definition;
}

Sequence *Sequence::attemptParse(FileReadInterface &input) {
    int pos = input.getPointer();
    std::vector<Matcher*> definition = {};
    std::string whitespace;
    Matcher* matcher = nullptr;
    if ((matcher = Matcher::attemptParse(input)) != nullptr) {
        definition.push_back(matcher);
        readWhitespace(input, whitespace);
        while (input[0] == '-' && input[1] == '>') {
            input.movePointer(2);
            readWhitespace(input, whitespace);
            if ((matcher = Matcher::attemptParse(input)) != nullptr) {
                definition.push_back(matcher);
            } else {
                std::cerr << "Sequence failed 1" << std::endl;
                input.setPointer(pos);
                return nullptr;
            }
        }
        readWhitespace(input, whitespace);
        return new Sequence(definition);
    } else {
        std::cerr << "Sequence failed 2" << std::endl;
        return nullptr;
    }
}
