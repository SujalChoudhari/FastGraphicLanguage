#pragma once

#include "../debug/Error.h"
#include "../blocks/Node.h"
#include "Number.h"

class Interpreter {
private:
	std::shared_ptr<Node> m_Ast;
	Error* m_Error;

public:
	Interpreter(Node ast, Error& error)
		: m_Ast(std::make_shared<Node>(ast)), m_Error(&error) {}

	std::shared_ptr<Number> runtime();

private:
	std::shared_ptr<Number> m_Visit(std::shared_ptr<Node> node);
	std::shared_ptr<Number> m_VisitNumberNode(std::shared_ptr<Node> node);
	std::shared_ptr<Number> m_VisitBinaryOperatorNode(std::shared_ptr<Node> node);
	std::shared_ptr<Number> m_VisitUnaryOperatorNode(std::shared_ptr<Node> node);
	std::shared_ptr<Number> m_VisitUnsupported(std::shared_ptr<Node> node);
};