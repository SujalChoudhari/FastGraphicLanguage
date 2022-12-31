#pragma once

#include <string>
#include <iostream>

#include "../constants.h"
#include "../debug/Position.h"


struct Token {
	std::string type;
	std::string value;
	Position startPosition;
	Position endPosition;

	Token(std::string type, std::string value, Position startPosition, Position endPosition)
		:type(type), value(value), startPosition(startPosition), endPosition(endPosition) {}

	Token(std::string type, std::string value, Position position)
		:type(type), value(value), startPosition(position), endPosition(position) {}

	Token(std::string type, Position position)
		:type(type), value(std::string()), startPosition(position), endPosition(position) {}

	Token(const Token& token)
		:type(token.type), value(token.value), startPosition(token.startPosition), endPosition(token.endPosition) {}

	friend std::ostream& operator<<(std::ostream& stream, const Token& t) {
		if (t.type == TOKEN_TYPE::INVALID_TOKEN) return stream;

		stream << "(" << t.type;

		if (!t.value.empty()) stream <<":" << t.value;
		stream << ")";

		return stream;
	}
};


