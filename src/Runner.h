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



		//for (auto t : lexer.getTokens()) {
		//	std::cout << t << std::endl;
		//}

		Parser parser = Parser(lexer.getTokens(), error);
		Node ast = parser.parse();
		if (error.count == 0)
			std::cout << ast << std::endl;

		Interpreter interpreter(ast, error);
		auto number = interpreter.runtime();
		std::cout << number->value << std::endl;
	}

};



