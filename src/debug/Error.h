#pragma once

#include <string>
#include "Position.h"


// Error Types

struct Error {
	unsigned int count= 0;
	static void InvalidCharacterError(char character, const Position& position);
	static void MultipleDecimalError(const Position& position);
	static void InvalidSyntaxError(std::string expected, std::string got, const Position& position);
};