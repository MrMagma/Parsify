//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_REFERENCE_H
#define PARSIFY_REFERENCE_H


#include <string>
#include "FileReadInterface.h"

class Reference {
public:
    explicit Reference(std::string name);
    std::string name;
    static Reference* attemptParse(FileReadInterface& input);
};


#endif //PARSIFY_REFERENCE_H
