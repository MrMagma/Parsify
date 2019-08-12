#include "Tokenizer/Token.h"
#include "Tokenizer/TokenStream.h"
#include "Parser/Syntax.h"

int main() {
    Token* t;
    TokenStream ts("../new-syntax.txt");
    Syntax* syntax = Syntax::attemptParse(ts);
    return 0;
}