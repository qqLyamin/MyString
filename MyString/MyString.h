#pragma once
#include <string>
#include <iostream>

class MyString
{
	char * m_pStr;
	static char m_pDefaultpStr[];

public:

	MyString(const char * initStr);
	MyString(const MyString & str);
	MyString(MyString && str);

	MyString& operator=(const char * initStr);
	MyString& operator=(const MyString & str);
	MyString& operator=(MyString && str);

	/*MyString operator+(const MyString & str);*/
	bool operator>(const MyString & right) const;
	bool operator<(const MyString & right) const;
	bool operator>=(const MyString & right) const;
	bool operator<=(const MyString & right) const;

	friend std::ostream& operator<<(std::ostream& MYCOUT, const MyString& MYSTR);

	MyString();
	~MyString();
};

