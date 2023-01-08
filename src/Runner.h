#pragma once

#include <iostream>

#include <string>
#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "runtime/Interpreter.h"
#include "Reader.h"
#include "debug/Error.h"

struct Runner {
	static void run(std::string filename)
	{
		Error error = Error();

		Reader reader = Reader(filename);
		Lexer lexer = Lexer(reader.getName(), reader.getText(), error);

		if (!error.IsSafe()) return;
		Parser parser = Parser(lexer.getTokens(), error);
		Node ast = parser.parse();


		if (!error.IsSafe()) return;

		Interpreter interpreter(ast, error);
		auto number = interpreter.runtime();
		std::cout << number->value << std::endl;
	}

};



