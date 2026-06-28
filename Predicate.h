#ifndef PREDICATE_H_
#define PREDICATE_H_
#include "Parameter.h"
#include <string>
#include <vector>

using namespace std;

class Predicate
{
private:
	string description;
	vector<Parameter> paravec; 

public:
	Predicate(void);
	~Predicate(void);
	void addparameter(Parameter param);
	void setdesc(string desc);
	string tostring();
};
#endif /* PREDICATE_H_ */
