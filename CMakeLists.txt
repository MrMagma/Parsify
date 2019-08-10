cmake_minimum_required(VERSION 3.14)
project(Parsify)

set(CMAKE_CXX_STANDARD 14)

add_executable(Parsify main.cpp Tokenizer/Token.h Tokenizer/TokenStream.h Tokenizer/TokenStream.cpp Parser/Parser.cpp Parser/Parser.h Parser/SyntaxDefinition.cpp Parser/SyntaxDefinition.h Parser/TokenDefinition.cpp Parser/TokenDefinition.h Translator/Translator.cpp Translator/Translator.h)