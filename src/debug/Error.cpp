
#include <iostream>
#include "Error.h"

void Error::InvalidCharacterError(char character, const Position& position)
{

	count++;
	std::cout
		<< "[INVALID CHARACTER]: Illegal Character '" << character << "' found at :\n "
		<< position.filename << " at line: " << position.lineNo << " ,column: " << position.column
		<< "\n\n";
}

void Error::MultipleDecimalError(const Position& position)
{
	count++;
	std::cout
		<< "[MULTIPLE DECIMAL]: A number cannot have more than 1 decimal point.\n"
		<< "Error at file: " << position.filename << ", line:" << position.lineNo << ", column: " << position.column
		<< "\n\n";
}

void Error::InvalidSyntaxError(std::string expected, std::string got, const Position& startPosition, const Position& endPosition)
{
	count++;
	std::cout
		<< "[INVALID SYNTAX]: Expected a (" << expected << ") but got (" << got << ") instead,\n at : "
		<< startPosition.filename << " at line: " << startPosition.lineNo << " ,column: " << startPosition.column
		<< "\n\n";
	showErrorInLine(startPosition, endPosition);
}

void Error::showErrorInLine(const Position& startPosition, const Position& endPosition)
{
	std::cout << "\n";
	std::cout << startPosition.line << "\n";

	for (int i = 0; i < endPosition.column; i++) {
		if (i < startPosition.column - 1) std::cout << "-";
		else std::cout << "^";
	}
	std::cout << "\n";
}

