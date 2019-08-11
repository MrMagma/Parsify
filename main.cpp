//#include "Translator/Translator.h"

#include <iostream>
#include "Parser2/Syntax.h"

int main() {
//    Translator translator("../syntax.txt", "../Tokenizer");
//    translator.tokenHeaderStubPath = "../stubs/Token.h";
//    translator.tokenStreamHeaderStubPath = "../stubs/TokenStream.h";
//    translator.tokenStreamSourceStubPath = "../stubs/TokenStream.cpp";
//    translator.translate();
    FileReadInterface file("../new-syntax.txt");
    Syntax* syntax = Syntax::attemptParse(file);
    std::cout << "Done" << std::endl;
    return 0;
}