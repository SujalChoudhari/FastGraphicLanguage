#pragma once
#include <string>

// TOKEN_TYPES
namespace TOKEN_TYPE {
	const std::string ASSIGNMENT	= "ASSIGNMENT";
	const std::string NUMBER		= "NUMBER";
	const std::string EQUALS		= "EQUALS";
	const std::string L_PAREN		= "L_PAREN";
	const std::string R_PAREN		= "R_PAREN";
	const std::string L_BRACE		= "L_BRACE";
	const std::string R_BRACE		= "R_BRACE";
	const std::string MULTIPLY		= "MULTIPLY";
	const std::string DEVIDE		= "DEVIDE";
	const std::string PLUS			= "PLUS";
	const std::string MINUS			= "MINUS";
	const std::string KEYWORD		= "KEYWORD";
	const std::string IDENTIFIER	= "IDENTIFIER";
	const std::string NEWLINE		= "NEWLINE";
	const std::string END_OF_FILE	= "EOF";
	const std::string INVALID_TOKEN = "INVALID_TOKEN";
}

// CHARACTER SET
const std::string DIGITS				= "0123456789";
const std::string DIGITS_WITH_DECIMAL	= DIGITS + ".";
const std::string SUPPORTED_NUMBERS		= DIGITS_WITH_DECIMAL + "_,";
const std::string LOWERCASE_ALPHABETS	= "abcdefghijklmnopqrstuvwxyz";
const std::string UPPERCASE_ALPHABETS	= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string ALPHABETS				= LOWERCASE_ALPHABETS + UPPERCASE_ALPHABETS;

// KEYWORDS
const std::string KEYWORDS[] = {
	"for",
	"if",
	"else",
	"elif",
	"null",
	"void",
};

// NODE TYPES
enum {
	NUMBER_NODE,
	BINARY_OP_NODE,
	UNARY_OP_NODE
};