//
// Created by Joshua on 8/10/2019.
//

#include <iostream>
#include "FileReadInterface.h"

FileReadInterface::FileReadInterface(const std::string& path) {
    file.open(path);
    if (!file.good()) {
        std::cerr << "Unable to open file \"" << path << "\"" << std::endl;
    }
}

char FileReadInterface::operator[](int i) {
    if (file.is_open()) {
        while (i >= buffer.length() && !file.eof()) buffer += char(file.get());
        if (i >= buffer.length()) return EOF;
        else return buffer[i];
    }
    return EOF;
}

void FileReadInterface::close() {
    if (file.is_open()) file.close();
    buffer = "";
}

unsigned long long FileReadInterface::length() {
    auto originalPos = file.tellg();
    file.seekg(0, std::ios::end);
    auto pos = file.tellg();
    file.seekg(originalPos);
    return pos;
}

FileReadInterface::~FileReadInterface() {
    close();
}

