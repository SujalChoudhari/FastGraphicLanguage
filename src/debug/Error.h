#pragma once

#include <string>
#include "Position.h"


// Error Types

struct Error {
	unsigned int count = 0;
	void InvalidCharacterError(char character, const Position& position);
	void MultipleDecimalError(const Position& position);
	void InvalidSyntaxError(std::string expected, std::string got, const Position& startPosition, const Position& endPosition);


private:
	void showErrorInLine(const Position& startPosition, const Position& endPosition);
};