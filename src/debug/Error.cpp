
#include <iostream>
#include "Error.h"

void Error::InvalidCharacterError(char character, const Position& position)
{
	
	std::cout
		<< "[INVALID CHARACTER]: Illegal Character '" << character << "' found at : "
		<< position.filename << " at line: " << position.lineNo << " ,column: " << position.column << std::endl;
}

void Error::MultipleDecimalError(const Position& position)
{
	
	std::cout
		<< "[MULTIPLE DECIMAL]: A number cannot have more than 1 decimal point.\n"
		<< "Error at file: " << position.filename << ", line:" << position.lineNo << ", column: " << position.column
		<< std::endl;
}

void Error::InvalidSyntaxError(std::string expected, std::string got, const Position& position) {
	
	std::cout
		<< "[INVALID SYNTAX]: Expected a (" << expected << ") but got (" << got << ") instead, at : "
		<< position.filename << " at line: " << position.lineNo << " ,column: " << position.column << std::endl;
}

