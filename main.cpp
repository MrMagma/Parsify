#include "Translator/Translator.h"

int main() {
    Translator t;
    t.inputPath = "../new-syntax.txt";
    t.tokenDefinitionPath = "../Tokenizer/TokenDefinition.cpp";
    t.tokenTypePath = "../Tokenizer/TokenType.h";
    t.tokenStreamHeaderPath = "TokenStream.h";
    t.translate();
    return 0;
}