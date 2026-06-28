/*
 * Token.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: msteve22
 */

#include "Token.h"

Token::Token(Type type, string desc, int line)
{
	token_type = type;
	description = desc;
	line_num = line;
}
Token::Token()
{
	token_type = COMMA;
	description = "";
	line_num = 0;
}
Token::~Token()
{
}
Type Token::getType()
{
	return token_type;
}
string Token::getDescription()
{
	return description;
}
int Token::getLineNumber()
{
	return line_num;
}
vector<Token> Token::scanToken()
{
	vector<Token> vecalec;
	return vecalec;
}
string Token::printToken()
{
	ostringstream temp;
	temp << line_num;
	return "(" + stokens[token_type] + ",\"" + description + "\"," + temp.str() + ")";
}
