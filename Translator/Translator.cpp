//
// Created by Joshua on 8/9/2019.
//

#include <regex>
#include <set>
#include "Translator.h"

Translator::Translator(const std::string& inputPath, const std::string& outputPath) {
    this->outputPath = outputPath;
}

void Translator::translate() {

}

std::string Translator::translateRegex(const std::string& regex) {
    std::regex replacer("(\\\\)");
    return std::regex_replace(regex, replacer, "\\$1");
}
