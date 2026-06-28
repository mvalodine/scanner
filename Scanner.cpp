/*
 * Scanner.cpp
 *
 *  Created on: Sep 16, 2014
 *      Author: msteve22
 */

#include "Scanner.h"

Scanner::Scanner(string input, string output)
{
	anything.open(input.c_str());
	line_number = 1; // or should it be zero?
	something = output;
	is_error = true; // initialize here?
}

Scanner::~Scanner()
{

}
void Scanner::scan_in()
{
	if(!anything.is_open())
	{
		cout << "Error, File Cannot Be Open. \n";
	}
	else
	{
		char c = anything.get();
		while(!anything.eof() && is_error)
		{
			new_token(c);
			c = anything.get();
		}
	}
}
bool Scanner::check_punct(char c)
{
	if(c == ',' || c== '.' || c == '?' || c== '(' ||c == ')')
	{
		return true;

	}
	else if(c == ':')
	{
		return true;
	}
	return false;
}

void Scanner::new_token(char c)
{
	
	if (check_punct(c))
	{
		is_punct(c);
	}
	else if(isalpha(c)) // but id can have a number
	{
		anything.putback(c);
		string tocheck = build_id();
		is_keyword(tocheck);
	}
	else if(c == '\'')
	{
		is_string();
	}
	else if(c == '#')
	{
		is_comment(); // will this be sufficient?
	}
	else if(c=='\n')
	{
		line_number++;
	}
	else if(c!=' ' && c!='\t')
	{
		cout << "Error, invalid Token.";
		is_error = false;
	}
}
vector<Token> Scanner::get_vec()
{
	return vec;
}
bool Scanner::is_punct(char c)
{
	if(c== ',')
	{
		vec.push_back(Token(COMMA, ",", line_number));
		return true;
	}
	else if(c== '.')
	{
		vec.push_back(Token(PERIOD, ".", line_number));
		return true;
	}
	else if(c== '?')
	{
		vec.push_back(Token(Q_MARK, "?", line_number));
		return true;
	}
	else if(c== '(')
	{
		vec.push_back(Token(LEFT_PAREN, "(", line_number));
		return true;
	}
	else if(c== ')')
	{
		vec.push_back(Token(RIGHT_PAREN, ")", line_number));
		return true;
	}
	else if(c==':')
	{
		is_colon(c);
		return true;
	}
	return false;

}
bool Scanner::is_colon(char c)
{
	char d = anything.get(); // gets the next character? or does it start over
	if(d == '-')
	{
		vec.push_back(Token(COLON_DASH, ":-", line_number));
		return true;
	}
	else
	{
		vec.push_back(Token(COLON, ":", line_number));
		anything.putback(d);
		return true;
	}
	return false;
}
string Scanner::build_id()
{
	string idstring;
	char d = anything.get();
	while (isalnum(d)) // while c is a letter or a number and nothing else
	{
		ostringstream temp;
		temp << d; //build the idstring
		idstring = idstring+temp.str();
		d = anything.get(); //gets the next character to check if it is a number or letter, does it start over?
	}
	anything.putback(d);
	return idstring;
}
bool Scanner::is_keyword(string tocheck)
{
	if (tocheck == "Facts")
	{
		vec.push_back(Token(FACTS, "Facts", line_number));
		return true;
	}
	else if (tocheck == "Schemes")
	{
		vec.push_back(Token(SCHEMES, "Schemes", line_number));
		return true;
	}
	else if (tocheck == "Rules")
	{
		vec.push_back(Token(RULES, "Rules", line_number));
		return true;
	}
	else if (tocheck == "Queries")
	{
		vec.push_back(Token(QUERIES, "Queries", line_number));
		return true;
	}
	else
	{
		vec.push_back(Token(ID, tocheck, line_number));
		return true;
	}
	return false;
}
bool Scanner::is_string()
{
	char c = anything.get();
	string stringaling;
	while(c!='\'')
	{
		if(anything.eof())
		{
			is_error = false;
			return false;
		}
		else if(c=='\n')
		{
			is_error = false;
			return false;
		}
		ostringstream temp;
		temp << c;
		stringaling = stringaling+temp.str();
		c = anything.get();
	}
	vec.push_back(Token(STRING, stringaling, line_number));
	return true;
}
void Scanner::is_comment()
{
	char c = anything.get();
	string stringaling;
	while(c!='\n' && !anything.eof())
	{
		c = anything.get();
	}
	line_number++;
}
void Scanner::save()
{
	ofstream outfile;
	outfile.open(something.c_str());
	for (int i=0; i<vec.size(); i++)
	{
		outfile << vec.at(i).printToken();
		outfile << endl;
	}
	if(!is_error)
	{
		outfile << "Input Error on line " << line_number;
	}
	else
	{
		outfile << "Total Tokens = " << vec.size() << endl;
	}
}
bool Scanner::get_error()
{
	return is_error;
}
int Scanner::returnlinenum()
{
	return line_number;
}

