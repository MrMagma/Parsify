//
// Created by Joshua on 8/10/2019.
//

#ifndef PARSIFY_BASECHECKS_H
#define PARSIFY_BASECHECKS_H

#include "FileReadInterface.h"

bool readCharacter(FileReadInterface& input, std::string& output, char stop = -1);

bool readInteger(FileReadInterface& input, std::string& output);

bool readWhitespace(FileReadInterface& input, std::string& output);

#endif //PARSIFY_BASECHECKS_H
