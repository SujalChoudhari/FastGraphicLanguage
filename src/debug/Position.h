#pragma once

#include <string>

struct Position {
	std::string filename;
	std::string line;
	int lineNo;
	int column;
	char character;
	int index;

	Position(std::string filename,std::string line, int lineNo, int column, char character)
		: filename(filename),line(line), lineNo(lineNo), column(column), character(character),index(-1) {}
};