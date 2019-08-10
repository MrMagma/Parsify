#include "Translator/Translator.h"

int main() {
    Translator translator("../syntax.txt", "../Tokenizer");
    translator.tokenHeaderStubPath = "../stubs/Token.h";
    translator.tokenStreamHeaderStubPath = "../stubs/TokenStream.h";
    translator.tokenStreamSourceStubPath = "../stubs/TokenStream.cpp";
    translator.translate();
    return 0;
}