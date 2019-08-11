//
// Created by Joshua on 8/10/2019.
//

#include "Checker.h"
#include "BaseChecks.h"

#include <utility>
#include <iostream>

Checker::Checker(std::string name, Sequence *sequence, Set *set, String *string, Reference *reference, Repeater *repeater) {
    this->name = std::move(name);
    this->sequence = sequence;
    this->set = set;
    this->string = string;
    this->reference = reference;
    this->repeater = repeater;
}

Checker *Checker::attemptParse(FileReadInterface& input) {
    int pos = input.getPointer();
    std::string name;
    Sequence* sequence = nullptr;
    Set* set = nullptr;
    String* string = nullptr;
    Reference* reference = nullptr;
    Repeater* repeater = nullptr;
    std::string whitespace;
    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z')) {
        name += input[0];
        input.movePointer(1);
        while ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= '0' && input[0] <= '9')) {
            name += input[0];
            input.movePointer(1);
        }
        readWhitespace(input, whitespace);
        if (input[0] == ':') {
            readWhitespace(input, whitespace);
            input.movePointer(1);
        } else {
            name = "";
            input.setPointer(pos);
        }
    }

    if (input[0] == '(') {
        input.movePointer(1);
        if ((sequence = Sequence::attemptParse(input)) != nullptr) {
            if (input[0] == ')') {
                input.movePointer(1);
            } else {
                delete sequence;
                sequence = nullptr;
                input.setPointer(pos);
            }
        }
    } else if ((set = Set::attemptParse(input)) != nullptr) {

    } else if ((string = String::attemptParse(input)) != nullptr) {

    } else if ((reference = Reference::attemptParse(input)) != nullptr) {

    } else {
        input.setPointer(pos);
        std::cerr << "Checker failed 1" << std::endl;
        return nullptr;
    }
    readWhitespace(input, whitespace);

    repeater = Repeater::attemptParse(input);

    return new Checker(name, sequence, set, string, reference, repeater);
}
