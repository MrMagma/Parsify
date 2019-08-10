//
// Created by Joshua on 8/9/2019.
//

#include <regex>
#include <set>
#include "Translator.h"

Translator::Translator(const std::string& inputPath, const std::string& outputPath) : parser(inputPath) {
    this->outputPath = outputPath;
}

void Translator::translate() {
    std::ofstream streamHeaderOutput(outputPath + "/TokenStream.h");
    std::ifstream streamHeaderInput(tokenStreamHeaderStubPath);
    if (!streamHeaderOutput.good()) return; // TODO Throw error
    while (streamHeaderInput.peek() != EOF) streamHeaderOutput << char(streamHeaderInput.get());
    streamHeaderInput.close();
    streamHeaderOutput.close();

    SyntaxDefinition* definition = parser.parse();
    std::ifstream tokenHeaderInput(tokenHeaderStubPath);
    std::ofstream tokenHeaderOutput(outputPath + "/Token.h");
    if (!tokenHeaderInput.good() || !tokenHeaderOutput.good()) return; // TODO Throw error
    tokenHeaderOutput << "#ifndef TOKENIZER_TOKEN_H\n#define TOKENIZER_TOKEN_H\n#define TOKENIZER_TOKEN_TOKENTYPES ";
    std::set<std::string> tokenTypes;
    for (TokenDefinition* td : definition->declarations) {
        if (td->name != "ignore" && tokenTypes.find(td->name) == tokenTypes.end()) {
            tokenTypes.insert(td->name);
        }
    }
    while (!tokenTypes.empty()) {
        tokenHeaderOutput << *tokenTypes.begin() << ", ";
        tokenTypes.erase(tokenTypes.begin());
    }
    tokenHeaderOutput << "End\n";
    while (tokenHeaderInput.peek() != EOF) tokenHeaderOutput << char(tokenHeaderInput.get());
    tokenHeaderOutput << "\n#endif\n";
    tokenHeaderInput.close();
    tokenHeaderOutput.close();

    std::ifstream streamSourceInput(tokenStreamSourceStubPath);
    std::ofstream streamSourceOutput(outputPath + "/TokenStream.cpp");
    if (!streamSourceInput.good() || !streamSourceInput.good()) return; // TODO Throw error
    while (streamSourceInput.peek() != EOF) streamSourceOutput << char(streamSourceInput.get());
    streamSourceInput.close();
    streamSourceOutput << "\n\nTokenStream& TokenStream::operator>>(Token*& outputLoc) {\n"
                          "    while (buffer.length() < TOKENSTREAM_BUFFER_SIZE && inputFile.peek() != EOF) buffer += char(inputFile.get());\n\n";
    for (auto* td : definition->declarations) {
        if (td->name == "ignore") {
            streamSourceOutput << "    if (matchToken(\"" << translateRegex(td->pattern) << "\", outputLoc, TokenType::End, true)) return *this;\n\n";
        } else {
            streamSourceOutput << "    if (matchToken(\"" << translateRegex(td->pattern) << "\", outputLoc, TokenType::" << td->name << ", false)) return *this;\n\n";
        }
    }
    streamSourceOutput << "    outputLoc = new Token(TokenType::End, \"\");\n"
                          "    return *this;\n"
                          "}";
    streamSourceOutput.close();
}

std::string Translator::translateRegex(const std::string& regex) {
    std::regex replacer("(\\\\)");
    return std::regex_replace(regex, replacer, "\\$1");
}
