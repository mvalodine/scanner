#include "Predicate.h"


Predicate::Predicate(void)
{
}
Predicate::~Predicate(void)
{
}
void Predicate::addparameter(Parameter param)
{
	paravec.push_back(param);
}
void Predicate::setdesc(string desc)
{
	description = desc;
}
string Predicate::tostring()
{
	string output;
	for(int i = 0; i<paravec.size(); i++)
	{
		if(i!=paravec.size()-1)
		{
			output += paravec[i].to_string() + ",";
		}
		else
		{
			output += paravec[i].to_string();
		}
	}
	return description + "(" + output + ")";
}
