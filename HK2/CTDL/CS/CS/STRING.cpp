#include "STRING.h"
#include <iostream>
#include <stdio.h>

STRING::STRING()
{
	length = 0;
	content = NULL;
}

STRING::STRING(const char* s)
{
	length = strlen(s);
	content = new CHAR[length];
	for (int i = 0; i < length; i++)
		content[i] = CHAR(s[i]);
}

STRING::STRING(const char& ch)
{
	length = 1;
	content = new CHAR[1];
	content[0] = CHAR(ch);
}



STRING::STRING(const CHAR& ch)
{
	length = 1;
	content = new CHAR[1];
	content[0] = ch;
}

STRING::STRING(const STRING& s)
{
	length = s.length;
	content = new CHAR[length];
	for (int i = 0; i < length; i++)
		content[i] = s.content[i];
}

STRING& STRING::expand(const CHAR& ch)
{
	CHAR* answer = new CHAR[length + 1];
	if (length != 0)
	{
		for (int i = 0; i < length; i++)
			answer[i] = content[i];
	}
	answer[length] = ch;
	delete[]content;
	content = answer;
	length++;
	return *this;
}

STRING& STRING::expand(const char& ch)
{
	CHAR* answer = new CHAR[length + 1];
	for (int i = 0; i < length; i++)
		answer[i] = content[i];
	delete[]content;
	answer[length] = CHAR(ch);
	content = answer;
	length++;
	return *this;
}

STRING& STRING::expand(const STRING& s)
{
	CHAR* answer = new CHAR[length + s.length];
	for (int i = 0; i < length; i++)
		answer[i] = content[i];
	delete[]content;
	for (int i = 0; i < s.length; i++)
		answer[i + length] = s.content[i];
	content = answer;
	length += s.length;
	return *this;
}

STRING& STRING::expand(const char* s)
{
	int lengthS = strlen(s);
	CHAR* answer = new CHAR[length + lengthS];
	for (int i = 0; i < length; i++)
		answer[i] = content[i];
	delete[]content;
	for (int i = 0; i < lengthS; i++)
		answer[i + length] = CHAR(s[i]);
	content = answer;
	length += lengthS;
	return *this;
}

STRING& STRING::remove(const CHAR& ch)
{
	STRING answer;
	char n = ch.getContent();
	for (int i = 0; i < length; i++)
		if (content[i].getContent() != n)
			answer.expand(content[i]);
	delete[]content;
	content = answer.content;
	length = answer.length;
	return *this;
}

STRING& STRING::remove(const char& ch)
{
	STRING answer;
	for (int i = 0; i < length; i++)
		if (content[i].getContent() != ch)
			answer.expand(content[i]);
	delete[]content;
	content = answer.content;
	length = answer.length;
	return *this;
}

STRING& STRING::input()
{
	std::cout << "Nhap string: ";
	STRING answer;
	char n;
	do
	{
		n = getchar();
		if (n != 10)
			answer.expand(n);
	} while (n != 10);
	delete[]content;
	content = answer.content;
	length = answer.length;
	return *this;
}

char* STRING::getContent()const
{
	char* answer = new char[length + 1];
	for (int i = 0; i < this->length; i++)
		answer[i] = content[i].getContent();
	answer[length] = '\0';
	return answer;
}