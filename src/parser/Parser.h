#pragma once
#include "Lexer.h"
#include "../blocks/Node.h"
#include "../blocks/Token.h"

class Parser {
private:
	std::vector<Token> m_Tokens;
	int m_TokenIndex;
	Token* m_CurrentToken;
	Error m_Error;

public:
	Parser(std::vector<Token> tokens,Error error);
	Node parse();

private:
	Token* m_Advance();

	void expression(std::shared_ptr<Node> outNode);
	void term(std::shared_ptr<Node> outNode);
	void factor(std::shared_ptr<Node> outNode);
};