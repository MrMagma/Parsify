//
// Created by Joshua on 8/10/2019.
//

#include <iostream>
#include "Matcher.h"
#include "BaseChecks.h"

Matcher::Matcher(std::vector<Checker *> &checks) {
    this->checks = checks;
}

Matcher *Matcher::attemptParse(FileReadInterface &input) {
    std::vector<Checker*> checks = {};
    Checker* check = nullptr;
    std::string whitespace;
    readWhitespace(input, whitespace);

    if ((check = Checker::attemptParse(input)) != nullptr) {
        checks.push_back(check);
        readWhitespace(input, whitespace);
        while (input[0] == '|') {
            readWhitespace(input, whitespace);
            input.movePointer(1);
            if ((check = Checker::attemptParse(input)) != nullptr) {
                checks.push_back(check);
                readWhitespace(input, whitespace);
            } else {
                std::cerr << "Matcher failed 1" << std::endl;
                return nullptr;
            }
        }
        return new Matcher(checks);
    } else {
        std::cerr << "Matcher failed 2" << std::endl;
        return nullptr;
    }
}
