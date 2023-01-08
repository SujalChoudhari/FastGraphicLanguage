#include <iostream>


#include "Lexer.h"
#include "../constants.h"
#include "../debug/Error.h"

std::vector<Token> Lexer::getTokens()
{
	m_Tokenize();
	return m_Tokens;
}

void Lexer::m_Advance(void)
{
	m_Position.column++;
	m_Position.index++;
	if (m_Position.index < text.length()) {
		m_CurrentChar = text[m_Position.index];
	}
	else {
		m_CurrentChar = '\0';
	}
}

void Lexer::m_Tokenize()
{
	while (m_Position.index < text.length()) {

		if (m_CurrentChar == ' ' || m_CurrentChar == '\t') {
			m_Advance();
		}
		else if (DIGITS.find(m_CurrentChar) != std::string::npos) {
			m_TokenizeDigits();
		}
		else if (ALPHABETS.find(m_CurrentChar) != std::string::npos) {
			m_TokenizeAlphabets();
		}
		else if (m_CurrentChar == '+') {
			m_Tokens.emplace_back(TOKEN_TYPE::PLUS, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == '-') {
			m_Tokens.emplace_back(TOKEN_TYPE::MINUS, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == '*') {
			m_TokenizeStars();
		}
		else if (m_CurrentChar == '/') {
			m_Tokens.emplace_back(TOKEN_TYPE::DIVIDE, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == '(') {
			m_Tokens.emplace_back(TOKEN_TYPE::L_PAREN, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == ')') {
			m_Tokens.emplace_back(TOKEN_TYPE::R_PAREN, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == '{') {
			m_Tokens.emplace_back(TOKEN_TYPE::L_BRACE, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == '}') {
			m_Tokens.emplace_back(TOKEN_TYPE::R_BRACE, "", m_Position);
			m_Advance();
		}
		else if (m_CurrentChar == '=') {
			m_TokenizeEquals();
		}
		else if (m_CurrentChar == '\n') {
			m_Tokens.emplace_back(TOKEN_TYPE::NEWLINE, m_Position);
			m_Position.column = 1;
			m_Position.lineNo++;
			m_Advance();
		}
		else {
			m_Error->InvalidCharacterError(m_CurrentChar, m_Position);
			m_Advance();
		}
	}
	m_Tokens.emplace_back(TOKEN_TYPE::END_OF_FILE, m_Position);
}

void Lexer::m_TokenizeDigits()
{
	std::string number;
	int decimalCount = 0;
	Position startPos = m_Position;

	while (SUPPORTED_NUMBERS.find(m_CurrentChar) != std::string::npos) {
		if (m_CurrentChar == '.') {
			if (decimalCount == 1) {
				m_Error->MultipleDecimalError(m_Position);
			}
			else {
				decimalCount++;
				number += '.';
			}
		}
		else if (m_CurrentChar != '_' && m_CurrentChar != ',') {
			number += m_CurrentChar;
		}

		m_Advance();
	}
	m_Tokens.emplace_back(TOKEN_TYPE::NUMBER, number,startPos, m_Position);
}

void Lexer::m_TokenizeAlphabets(void)
{
	std::string identifier;
	Position startPos = m_Position;
	while (ALPHABETS.find(m_CurrentChar) != std::string::npos) {
		identifier += m_CurrentChar;
		m_Advance();
	}

	for (std::string keyword : KEYWORDS) {
		if (keyword == identifier) {
			m_Tokens.emplace_back(TOKEN_TYPE::KEYWORD, identifier, startPos,m_Position);
			return;
		}
	}

	m_Tokens.emplace_back(TOKEN_TYPE::IDENTIFIER, identifier, startPos, m_Position);
}

void Lexer::m_TokenizeEquals(void)
{
	Position startPos = m_Position;
	m_Advance();
	if (m_CurrentChar == '=') {
		m_Tokens.emplace_back(TOKEN_TYPE::EQUALS, "",startPos, m_Position);
	}
	else {
		m_Tokens.emplace_back(TOKEN_TYPE::ASSIGNMENT, "",startPos, m_Position);
	}
	m_Advance();
}


void Lexer::m_TokenizeStars(void)
{
	Position startPos = m_Position;
	m_Advance();
	if (m_CurrentChar == '*') {
		m_Tokens.emplace_back(TOKEN_TYPE::POWER, "", startPos, m_Position);
		m_Advance();
	}
	else {
		m_Tokens.emplace_back(TOKEN_TYPE::MULTIPLY, "", startPos, m_Position);
	}
}