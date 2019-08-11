//
// Created by Joshua on 8/11/2019.
//

#ifndef PARSIFY_SEQUENCE_H
#define PARSIFY_SEQUENCE_H

#include <vector>
#include "Matcher.h"

class Matcher;

class Sequence {
public:
    explicit Sequence(std::vector<Matcher*>& definition);
    std::vector<Matcher*> definition = {};
    static Sequence* attemptParse(FileReadInterface& input);
};


#endif //PARSIFY_SEQUENCE_H
