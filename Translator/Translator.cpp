//
// Created by Joshua on 8/9/2019.
//

#include <set>
#include "Translator.h"
#include "../Tokenizer/TokenStream.h"
#include "../Parser/Syntax.h"
#include "../Parser/TokenDefinition.h"

void Translator::translate() {
    TokenStream ts(inputPath);
    Syntax* syntax = Syntax::attemptParse(ts);
    if (syntax != nullptr) {
        std::set<std::string> tokenTypes = {endTokenName};
        std::ofstream definitionOutputFile(tokenDefinitionPath);
        if (definitionOutputFile.is_open()) {
            definitionOutputFile << "#include \"" << tokenStreamHeaderPath << "\"\n\nvoid TokenStream::defineTokens() {\n";
            for (Definition* d : syntax->definitions) {
                if (auto* td = dynamic_cast<TokenDefinition*>(d)) {
                    // It's four spaces, you nerds
                    definitionOutputFile << "    matchers.push_back(Matcher{std::regex(\"" << translateRegex(td->expression) << "\"), TokenType::" << td->name << "});\n";
                    tokenTypes.insert(td->name);
                }
            }
            definitionOutputFile << "}";
            definitionOutputFile.close();
        }

        std::ofstream typeOutputFile(tokenTypePath);
        if (typeOutputFile.is_open()) {
            typeOutputFile << "#ifndef TOKEN_TYPE_HEADER\n#define TOKEN_TYPE_HEADER\n\nenum class TokenType {\n";
            for (auto it = tokenTypes.begin(); it != tokenTypes.end(); ++it) {
                typeOutputFile << "    " << *it;
                if (it != --tokenTypes.end()) typeOutputFile << ",";
                typeOutputFile << "\n";
            }
            typeOutputFile << "};\n\n#endif";
            typeOutputFile.close();
        }
    }
}

std::string Translator::translateRegex(const std::string& regex) {
    std::regex replacer("(\\\\)");
    return std::regex_replace(regex, replacer, "\\$1");
}
