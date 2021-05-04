#pragma once
#include "CHAR.h"

using namespace std;
class STRING
{
private:
	CHAR* content;
	int length;
public:
	STRING();
	STRING(const char*);
	STRING(const char&);
	STRING(const CHAR&);
	STRING(const STRING&);

	STRING& expand(const CHAR&);
	STRING& expand(const char&);
	STRING& expand(const STRING&);
	STRING& expand(const char*);

	STRING& remove(const CHAR&);
	STRING& remove(const char&);

	STRING& input();
	char* getContent() const;
};