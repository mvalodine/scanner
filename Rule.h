#ifndef RULE_H_
#define RULE_H_
#include "Predicate.h"
#include <vector>

using namespace std;

class Rule
{
private:
	Predicate pred;
	vector<Predicate> predvec;

public:
	Rule(void);
	~Rule(void);
	void addpred(Predicate predaled);
	void set_pred(Predicate p);
	string tostring();
};

#endif /* RULE_H_ */

