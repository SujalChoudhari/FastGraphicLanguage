#include "Parser.h"
#include "../debug/Error.h"

Parser::Parser(std::vector<Token> tokens)
{
	m_Tokens = tokens;
	m_TokenIndex = -1;
	m_CurrentToken = nullptr;
	m_Advance();
	m_Error = Error();
}

Token* Parser::m_Advance()
{
	m_TokenIndex++;
	if (m_TokenIndex < m_Tokens.size()) {
		m_CurrentToken = &m_Tokens.at(m_TokenIndex);

	}
	return m_CurrentToken;
}

Node Parser::parse()
{
	std::shared_ptr<Node> result = std::make_shared<Node>(0, *m_CurrentToken);
	expression(result);
	while (result->left != nullptr && result->right == nullptr && result->value.type != TOKEN_TYPE::INVALID_TOKEN) {
		result = result->left;
	}

	return *result.get();
}

void Parser::expression(std::shared_ptr<Node>outNode)
{
	std::shared_ptr< Node >left = std::make_shared<Node>(0, *m_CurrentToken);
	term(left);
	while (left->left != nullptr && left->right == nullptr && left->value.type != TOKEN_TYPE::INVALID_TOKEN) {
		left = left->left;
	}

	while (m_CurrentToken->type == TOKEN_TYPE::PLUS
		|| m_CurrentToken->type == TOKEN_TYPE::MINUS) {
		Token opTok = *m_CurrentToken;
		m_Advance();

		std::shared_ptr<Node> right = std::make_shared< Node>(0, *m_CurrentToken);
		term(right);

		while (right->left != nullptr && right->right == nullptr && right->value.type != TOKEN_TYPE::INVALID_TOKEN) {
			right = right->left;
		}

		left = std::make_shared<Node>(BINARY_OP_NODE, left, opTok, right);


	}
	outNode->type = BINARY_OP_NODE;
	outNode->left = left;
	outNode->value = Token(TOKEN_TYPE::INVALID_TOKEN, m_CurrentToken->startPosition);
	outNode->right = nullptr;
}

void Parser::term(std::shared_ptr<Node>outNode)
{
	std::shared_ptr<Node >left = std::make_shared<Node>(0, *m_CurrentToken);
	factor(left);

	while (m_CurrentToken->type == TOKEN_TYPE::MULTIPLY
		|| m_CurrentToken->type == TOKEN_TYPE::DEVIDE) {
		Token opTok = *m_CurrentToken;
		m_Advance();

		std::shared_ptr<Node> right = std::make_shared<Node>(0, *m_CurrentToken);
		factor(right);

		left = std::make_shared<Node>(BINARY_OP_NODE, left, opTok, right);

	}
	outNode->type = BINARY_OP_NODE;
	outNode->left = left;
	outNode->value = Token(TOKEN_TYPE::INVALID_TOKEN, m_CurrentToken->startPosition);
	outNode->right = nullptr;
}

void Parser::factor(std::shared_ptr<Node> outNode)
{
	Token token = *m_CurrentToken;

	if (token.type == TOKEN_TYPE::PLUS || token.type == TOKEN_TYPE::MINUS) {
		m_Advance();
		std::shared_ptr<Node> number = std::make_shared<Node>(0, *m_CurrentToken);
		factor(number);

		outNode->type = UNARY_OP_NODE;
		outNode->left = number;
		outNode->value = token;
		outNode->right = nullptr;
	}
	else if (token.type == TOKEN_TYPE::L_PAREN) {
		m_Advance();
		std::shared_ptr<Node> expr = std::make_shared<Node>(0, *m_CurrentToken);
		expression(expr);
		if (m_CurrentToken->type == TOKEN_TYPE::R_PAREN) {
			m_Advance();
			outNode->left = expr->left;
			outNode->right = expr->right;
			outNode->type = expr->type;
			outNode->value = expr->value;
		}
		else {
			m_Error.InvalidSyntaxError(TOKEN_TYPE::R_PAREN, m_CurrentToken->type, m_CurrentToken->startPosition, m_CurrentToken->endPosition);
		}
	}

	else if (token.type == TOKEN_TYPE::NUMBER) {
		m_Advance();
		outNode->type = NUMBER_NODE;
		outNode->left = nullptr;
		outNode->value = token;
		outNode->right = nullptr;
	}
	else {
		m_Error.InvalidSyntaxError(TOKEN_TYPE::NUMBER, token.type, token.startPosition, token.endPosition);
	}
}


