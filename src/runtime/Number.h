#pragma once

#include "../debug/Position.h"

struct Number {
public:
	Position startPosition;
	Position endPosition;
	float value;

public:

	Number()
		:startPosition(Position("", "", 0, 0, 0)), endPosition(startPosition), value(0.0f) {}

	Number(float value)
		:startPosition(Position("", "", 0, 0, 0)), endPosition(startPosition), value(value) {}

	Number(std::string textValue)
		:startPosition(Position("", "", 0, 0, 0)), endPosition(startPosition), value(std::stof(textValue)) {}

	Number(std::string textValue, Position position)
		:startPosition(position), endPosition(startPosition), value(std::stof(textValue)) {}

	Number(float value, Position Position)
		:startPosition(startPosition), endPosition(startPosition), value(value) {}


	void setPosition(Position start, Position end) {
		startPosition = start;
		endPosition = end;
	}

	std::shared_ptr<Number> add(Number other) {
		return std::make_shared<Number>(value + other.value);
	}

	std::shared_ptr<Number> minus(Number other) {
		return std::make_shared<Number>(value - other.value);
	}
	std::shared_ptr<Number> multiply(Number other) {
		return std::make_shared<Number>(value * other.value);
	}
	std::shared_ptr<Number> divide(Number other) {
		return std::make_shared<Number>(value / other.value);
	}
};