cmake_minimum_required(VERSION 3.14)
project(Parsify)

set(CMAKE_CXX_STANDARD 14)

add_executable(Parsify main.cpp Tokenizer/Token.h Tokenizer/TokenStream.h Tokenizer/TokenStream.cpp Parser/Parser.cpp Parser/Parser.h Parser/SyntaxDefinition.cpp Parser/SyntaxDefinition.h Parser/TokenDefinition.cpp Parser/TokenDefinition.h Translator/Translator.cpp Translator/Translator.h Parser2/Syntax.cpp Parser2/Syntax.h Parser2/Rule.cpp Parser2/Rule.h Parser2/Matcher.cpp Parser2/Matcher.h Parser2/Checker.cpp Parser2/Checker.h Parser2/Repeater.cpp Parser2/Repeater.h Parser2/Set.cpp Parser2/Set.h Parser2/String.cpp Parser2/String.h Parser2/FileReadInterface.cpp Parser2/FileReadInterface.h Parser2/BaseChecks.h Parser2/BaseChecks.cpp Parser2/Reference.cpp Parser2/Reference.h Parser2/Sequence.cpp Parser2/Sequence.h)