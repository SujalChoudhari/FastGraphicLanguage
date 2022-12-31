#pragma once

#include <string>
#include <vector>

#include "../debug/Position.h"
#include "../blocks/Token.h"

class Lexer {
public:
	std::string filename;
	std::string text;

private:
	Position m_Position;
	char m_CurrentChar;
	std::vector<Token> m_Tokens;


public:
	Lexer(std::string filename, std::string text)
		:filename(filename), text(text), m_Position({ filename, 1, 0, 0 }) {
		m_Advance();
	}


	std::vector<Token>getTokens();

private:
	void m_Advance(void);
	void m_Tokenize(void);
	void m_TokenizeDigits(void);
	void m_TokenizeAlphabets(void);
	void m_TokenizeEquals(void);
};