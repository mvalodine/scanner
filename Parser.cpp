#include "Parser.h"
	Parser::Parser(vector<Token> invec, string output)
	{
		tokens = invec;
		outputfile = output;
		iterator = 1;
	}
	Parser::~Parser()
	{
	}
	void Parser::Parse()
	{
		current = tokens[0];
		match(SCHEMES);
		match(COLON);
		schemelist();
		match(FACTS);
		match(COLON);
		factlist();
		match(RULES);
		match(COLON);
		rulelist();
		match(QUERIES);
		match(COLON);
		querylist();

	}
	void Parser::match(Type tokentype)
	{
		if(current.getType()==tokentype)
		{	
			if(iterator<tokens.size())
			{
				current = tokens[iterator];
				iterator++;
			}
			else
			{
				current = Token(FINAL, "", 0);
			}

		}
		else
		{
			throw current;
		}
	}
	void Parser::schemelist() 
	{
		predicate();
		schemevec.push_back(p);
		if(current.getType()!=FACTS)
		{
			schemelist();
		}
	}
	void Parser::factlist() 
	{
		if(current.getType()!=RULES)
		{
			predicate();
			factvec.push_back(p);
			match(PERIOD);
			factlist();
		}
	}
	Rule r;
	void Parser::rulelist() // can do rule and rule list, empty, or predicate and colon dash and predicatelist
	{
		r = Rule();
		if(current.getType()!=QUERIES)
		{
			predicate();
			r.set_pred(p);
			match(COLON_DASH);
			while(current.getType()!=PERIOD)
			{
				predicate();
				r.addpred(p);
				if(current.getType()!=PERIOD)
				{
					match(COMMA);
				}
			}
			match(PERIOD);
			rulevec.push_back(r);
			rulelist();
		}
	}
	void Parser::querylist() 
	{
		predicate(); 
		queryvec.push_back(p);
		match(Q_MARK);
		if(current.getType()==ID)
		{
			querylist();
		}
		else if(current.getType()!=FINAL)
		{
			throw current;
		}
	}
	void Parser::parameterlist()
	{
		parameter();
		if(current.getType()==COMMA)
		{
			match(COMMA);
			parameterlist();
		}
	}
	void Parser::predicate() // can do predicate comma predicate list, predicate, or identifier leftparen parameterlist rightparen
	{
		p = Predicate();
		p.setdesc(current.getDescription());
		match(ID);
		match(LEFT_PAREN);
		parameterlist(); 
		match(RIGHT_PAREN);
	}
	void Parser::parameter() 
	{
		Parameter param;
		if(current.getType()==ID)
		{
			param.set_id(current.getDescription());
			match(ID);
			p.addparameter(param);
		}
		else if(current.getType()==STRING)
		{
			param.set_string(current.getDescription());
			int verify = 0;
			for(int i = 0; i<domainvec.size(); i++)
			{
				if(domainvec[i] == current.getDescription())
				{
					verify = 1;
				}
			}
			if(verify != 1)
			{
				domainvec.push_back(current.getDescription());
			}
			match(STRING);
			p.addparameter(param);
		}
		else
		{
			throw current;
		}
	}
	void Parser::print()
	{
		ofstream outfile;
		outfile.open(outputfile.c_str());
		outfile << "Success!\n";
		outfile << "Schemes(" << schemevec.size() << "):\n";
		for(int i = 0; i<schemevec.size(); i++)
		{
			outfile << "  " + schemevec[i].tostring() + "\n";
		}
		outfile << "Facts(" << factvec.size() << "):\n";
		for(int i = 0; i<factvec.size(); i++)
		{
			outfile << "  " + factvec[i].tostring() + "\n";
		}
		outfile << "Rules(" << rulevec.size() << "):\n";
		for(int i = 0; i<rulevec.size(); i++)
		{
			outfile << "  " + rulevec[i].tostring() + "\n";
		}
		outfile << "Queries(" << queryvec.size() << "):\n";
		for(int i = 0; i<queryvec.size(); i++)
		{
			outfile << "  " + queryvec[i].tostring() + "\n";
		}
		outfile << "Domain(" << domainvec.size() << "):\n";
		sort(domainvec.begin(), domainvec.end());
		for(int i = 0; i<domainvec.size(); i++)
		{
			outfile << "  '" + domainvec[i] + "'\n";
		}
	}

