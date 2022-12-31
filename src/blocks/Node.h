#pragma once
#include <string>
#include <iostream>


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
		if (node.left.get() != nullptr) 		// if there is a left node
			stream << *node.left;
		if (node.value.type != TOKEN_TYPE::INVALID_TOKEN) 	// if there is a token 
			stream << " " << node.value;
		if (node.right != nullptr) 			// if there is a right node
			stream << " " << *node.right.get();

		stream << "}";
		return stream;

	}


};



