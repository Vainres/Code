#include <iostream>
#include "STRING.h"

using namespace std;

int main()
{
	CHAR c1, c2('c');
	STRING s1, s2("s2"), s3('a'), s4(c1), s5(s4);
	s1.expand(c2).expand('a').expand(s2).expand("abc");//s1: "cas2abc"
	cout << s1.getContent();
	s1.remove(c2).remove('d');//remove all character c2 in s1 -- s1: "as2ab"
	s1.input();//nhập chuỗi mới từ bàn phím
	cout << s1.getContent();
	cout << c1.getContent();
	return 0;
}