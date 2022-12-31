#include <iostream>

#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "Reader.h"
#include "debug/Error.h"

int main(void) {

	Reader reader("D:/C++/FastGraphicLanguage/tests/test.fgl");

	Lexer lexer(reader.getName(), reader.getText());

	for (auto t : lexer.getTokens()) {
		std::cout << t;
	}
	std::cout << "\n\n";

	Parser parser(lexer.getTokens());
	Node ast = parser.parse();
	std::cout << ast << std::endl;
}
