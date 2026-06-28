/*
 * Token.h
 *
 *  Created on: Sep 16, 2014
 *      Author: msteve22
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <sstream>
#include <vector>

using namespace std;

enum Type {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, FINAL
};

const string stokens[13] = {"COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON", "COLON_DASH", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID", "STRING"
};

class Token {

private:
	Type token_type;
	string description;
	int line_num;


public:
	Token(Type token_type, string description, int line_num);
	Token();
	virtual ~Token();
	Type getType();
	string getDescription();
	int getLineNumber();
	vector<Token> scanToken();
	string printToken();
};

#endif /* TOKEN_H_ */
