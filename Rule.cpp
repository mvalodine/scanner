#include "Rule.h"


Rule::Rule(void)
{
}
Rule::~Rule(void)
{
}
void Rule::addpred(Predicate predaled)
{
	predvec.push_back(predaled);
}
void Rule::set_pred(Predicate p)
{
	pred = p;
}
string Rule::tostring()
{
	string output = pred.tostring() + " :- ";

	for(int i = 0; i<predvec.size(); i++)
	{
		if(i!=predvec.size()-1)
		{
		output += predvec[i].tostring() + ",";
		}
		else
		{
			output += predvec[i].tostring();
		}
	}
	return output;
}
