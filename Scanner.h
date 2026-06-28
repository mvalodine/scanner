/*
 * Scanner.h
 *
 *  Created on: Sep 16, 2014
 *      Author: msteve22
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include "Token.h"

using namespace std;

class Scanner {

private:
	ifstream anything;
	string something;
	int line_number;
	vector<Token> vec;
	bool is_error;
public:
	Scanner(string input, string output);
	virtual ~Scanner();
	void scan_in();
	void new_token(char c);
	vector<Token> get_vec();
	bool check_punct(char c);
	bool is_punct(char c);
	bool is_colon(char c);
	string build_id();
	bool is_keyword(string);
	bool is_id(string); 
	bool is_string();
	void is_comment();
	void save();
	bool get_error();
	int returnlinenum();
};

#endif /* SCANNER_H_ */
