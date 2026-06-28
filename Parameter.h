#ifndef PARAMETER_H_
#define PARAMETER_H_
#include <string>

using namespace std;

class Parameter
{
private:
	string identifier;
	string stringaling;
	bool has_id;
public:
	Parameter();
	virtual ~Parameter();
	bool is_id();
	void set_id(string id);
	void set_string(string stringthing);
	string to_string();
};
#endif /* PARAMETER_H_ */

