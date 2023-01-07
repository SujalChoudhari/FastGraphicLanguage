#include "../Constants.h"
#include "Interpreter.h"

std::shared_ptr<Number> Interpreter::runtime()
{
	return m_Visit(m_Ast);
}

std::shared_ptr<Number> Interpreter::m_Visit(std::shared_ptr<Node> node)
{
	switch (node->type) {
	case NUMBER_NODE:
		return m_VisitNumberNode(node);
		break;
	case BINARY_OP_NODE:
		return m_VisitBinaryOperatorNode(node);
		break;
	case UNARY_OP_NODE:
		return m_VisitUnaryOperatorNode(node);
		break;
	default:
		return m_VisitUnsupported(node);
		break;
	}


}

std::shared_ptr<Number> Interpreter::m_VisitNumberNode(std::shared_ptr<Node> node)
{
	std::shared_ptr<Number> result;
	result = std::make_shared<Number>(node->value.value);
	result->setPosition(node->value.startPosition, node->value.endPosition);
	return result;
}

std::shared_ptr<Number> Interpreter::m_VisitBinaryOperatorNode(std::shared_ptr<Node> node)
{
	auto left = m_Visit(node->left);
	auto right = m_Visit(node->right);
	std::shared_ptr<Number> result;

	if (node->value.type == TOKEN_TYPE::PLUS)
	{
		result = left->add(*right);
	}
	else if (node->value.type == TOKEN_TYPE::MINUS)
	{
		result = left->minus(*right);
	}
	else if (node->value.type == TOKEN_TYPE::MULTIPLY)
	{
		result = left->multiply(*right);
	}
	else if (node->value.type == TOKEN_TYPE::DIVIDE)
	{
		result = left->divide(*right);
	}

	result->setPosition(node->value.startPosition, node->value.endPosition);
	return result;
}

std::shared_ptr<Number> Interpreter::m_VisitUnaryOperatorNode(std::shared_ptr<Node> node)
{
	auto number = m_Visit(node->left);
	number->setPosition(node->value.startPosition, node->value.endPosition);
	if (node->value.type == TOKEN_TYPE::MINUS) {
		return number->multiply(Number(-1));
	}
	else return number;
}

std::shared_ptr<Number> Interpreter::m_VisitUnsupported(std::shared_ptr<Node> node)
{
	return std::shared_ptr<Number>();
}
