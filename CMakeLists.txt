cmake_minimum_required(VERSION 3.14)
project(Parsify)

set(CMAKE_CXX_STANDARD 14)

add_executable(Parsify main.cpp Tokenizer/Token.h Tokenizer/TokenStream.h Tokenizer/TokenStream.cpp Tokenizer/TokenDefinition.cpp Translator/Translator.cpp Translator/Translator.h Parser/Definition.h Parser/TokenDefinition.cpp Parser/TokenDefinition.h Parser/Definition.cpp Parser/Syntax.cpp Parser/Syntax.h Tokenizer/TokenType.h Parser/NodeDefinition.cpp Parser/NodeDefinition.h Parser/PropertyDefinition.cpp Parser/PropertyDefinition.h)