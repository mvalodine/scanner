
#ifndef PARSER_H_
#define PARSER_H_

#include "Scanner.h"
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Parser 
{
private:
	vector<Token> tokens;
	string outputfile;
	Token current;
	int iterator;
	vector<Predicate> schemevec;
	vector<Predicate> factvec;
	vector<Predicate> queryvec;
	vector<Rule> rulevec;
	vector<string> domainvec;
	Predicate p;
	
public:
	Parser(vector<Token> invec, string output);
	void Parse();
	virtual ~Parser();
	void match(Type tokentype);
	void schemelist();
	void factlist();
	void rulelist();
	void querylist();
	void parameterlist();
	void predicate();
	void parameter();
	void print();
	
};

#endif /* PARSER_H_ */