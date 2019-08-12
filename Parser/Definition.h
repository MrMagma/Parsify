//
// Created by Joshua on 8/11/2019.
//

#ifndef PARSIFY_DEFINITION_H
#define PARSIFY_DEFINITION_H


#include <string>

class Definition {
public:
    explicit Definition(std::string name);
    // TODO This should convert a node to source code
    virtual void toSourceCode() {};
    std::string name;
};


#endif //PARSIFY_DEFINITION_H
