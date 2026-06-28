#include "Parameter.h"

Parameter::Parameter()
{
}
Parameter::~Parameter()
{
}
bool Parameter::is_id()
{
	return has_id;
}
void Parameter::set_id(string id)
{
	identifier = id;
	has_id = true;
}
void Parameter::set_string(string stringthing)
{
	stringaling = stringthing;
	has_id = false;
}
string Parameter::to_string()
{
	if (has_id)
	{
		return identifier;
	}
	else
	{
		return "'" + stringaling +"'";
	}
}