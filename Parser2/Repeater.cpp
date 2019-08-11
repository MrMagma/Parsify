//
// Created by Joshua on 8/10/2019.
//

#include "Repeater.h"
#include "BaseChecks.h"

#include <utility>
#include <iostream>

Repeater::Repeater(std::string content) {
    this->content = std::move(content);
}

Repeater *Repeater::attemptParse(FileReadInterface& input) {
    int pos = input.getPointer();
    std::string content;
    if (input[0] == '*' || input[0] == '+' || input[0] == '?') {
        content += input[0];
        input.movePointer(1);
        return new Repeater(content);
    } else if (input[0] == '{') {
        input.movePointer(1);
        if (input[0] == ',') {
            content += ",";
            input.movePointer(1);
            if (input[0] == '}') {
                input.movePointer(1);
                return new Repeater(content);
            } else if (readInteger(input, content)) {
                if (input[0] == '}') {
                    input.movePointer(1);
                    return new Repeater(content);
                } else {
                    input.setPointer(pos);
                    std::cerr << "Repeater failed 1" << std::endl;
                    return nullptr;
                }
            } else {
                input.setPointer(pos);
                std::cerr << "Repeater failed 2" << std::endl;
                return nullptr;
            }
        } else if (readInteger(input, content)) {
            if (input[0] == '}') {
                input.movePointer(1);
                return new Repeater(content);
            } else if (input[0] == ',') {
                content += ",";
                input.movePointer(1);
                if (input[0] == '}') {
                    input.movePointer(1);
                    return new Repeater(content);
                } else if (readInteger(input, content)) {
                    if (input[0] == '}') {
                        input.movePointer(1);
                        return new Repeater(content);
                    } else {
                        input.setPointer(pos);
                        std::cerr << "Repeater failed 3" << std::endl;
                        return nullptr;
                    }
                } else {
                    input.setPointer(pos);
                    std::cerr << "Repeater failed 4" << std::endl;
                    return nullptr;
                }
            } else {
                std::cerr << "Repeater failed 5" << std::endl;
                return nullptr;
            }
        } else {
            input.setPointer(pos);
            std::cerr << "Repeater failed 6" << std::endl;
            return nullptr;
        }
    } else {
        std::cerr << "Repeater failed 7" << std::endl;
        return nullptr;
    }
}
