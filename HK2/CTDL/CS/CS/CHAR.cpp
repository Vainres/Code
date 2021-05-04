#include "CHAR.h"

CHAR::CHAR()
{
	content = '\0';
}

CHAR::CHAR(char ch)
{
	content = ch;
}

char CHAR::getContent() const
{
	return content;
}
