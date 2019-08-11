//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_CHECKER_H
#define PARSIFY_CHECKER_H


#include <string>
#include "Reference.h"
#include "Repeater.h"
#include "Set.h"
#include "String.h"
#include "Matcher.h"
#include "Sequence.h"

class Sequence;

class Checker {
public:
    Checker(std::string name, Sequence* sequence, Set* set, String* string, Reference* reference, Repeater* repeater);
    std::string name = "";
    Sequence* sequence;
    Set* set;
    String* string;
    Reference* reference;
    Repeater* repeater = nullptr;
    static Checker* attemptParse(FileReadInterface& input);
};


#endif //PARSIFY_CHECKER_H
