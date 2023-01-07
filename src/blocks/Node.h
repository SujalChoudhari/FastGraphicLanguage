#pragma once
#include <string>
#include <iostream>
#include "Token.h"

struct Node {
	int type;
	std::shared_ptr<Node> left;
	Token value;
	std::shared_ptr<Node> right;

	Node(int type, std::shared_ptr<Node> left, Token value, std::shared_ptr<Node> right)
		:type(type), left(left), value(value), right(right) {}

	Node(int type, std::shared_ptr<Node> left, Token value)
		:type(type), left(left), value(value), right(nullptr) {}

	Node(int type, Token value)
		:type(type), left(nullptr), value(value), right(nullptr) {}


	friend std::ostream& operator<<(std::ostream& stream, const Node& node) {
		stream << "{";
		if (node.left != nullptr) {
			stream << *node.left.get();
		}
		stream << node.value;

		if (node.right != nullptr) {
			stream << *node.right.get();
		}
		stream << "}";
		return stream;

	}


};



