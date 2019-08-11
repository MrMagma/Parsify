//
// Created by Joshua on 8/10/2019.
//

#include "BaseChecks.h"

bool readCharacter(FileReadInterface& input, std::string& output, char stop) {
    int pos = input.getPointer();
    if (input[0] == stop) return false;
    if (input[0] == '\\') {
        output += input[0];
        input.movePointer(1);
        if (input[0] == '\"' || input[0] == '\\' || input[0] == '/' || input[0] == 'b' || input[0] == 'f' || input[0] == 'n' || input[0] == 'r' || input[0] == 't') {
            output += input[0];
            input.movePointer(1);
            return true;
        } else if (input[0] == 'u') {
            output += input[0];
            input.movePointer(1);
            for (int i = 0; i < 4; i++) {
                if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
                    output += input[i];
                } else {
                    input.setPointer(pos);
                    output = output.substr(output.length() - i, i - 1);
                    return false;
                }
            }
            input.movePointer(4);
            return true;
        } else {
            input.setPointer(pos);
            output = output.substr(output.length() - 1, 1);
            return false;
        }
    } else if (input[0] != '\\') {
        output += input[0];
        input.movePointer(1);
        return true;
    } else {
        input.setPointer(pos);
        return false;
    }
}

bool readInteger(FileReadInterface& input, std::string& output) {
    if (input[0] >= '1' && input[0] <= '9') {
        output += input[0];
        input.movePointer(1);
        while (input[0] >= '0' && input[0] <= '9') {
            output += input[0];
            input.movePointer(1);
        }
        return true;
    } else {
        return false;
    }
}

bool readWhitespace(FileReadInterface& input, std::string& output) {
    while (input[0] == ' ' || input[0] == '\t' || input[0] == '\n' || input[0] == '\r') input.movePointer(1);
    return true;
}