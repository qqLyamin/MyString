#include "MyString.h"
char MyString::m_pDefaultpStr[] = {""}; //изменение

MyString::MyString()
{
	m_pStr = m_pDefaultpStr;
}

MyString::~MyString()
{
	if (m_pStr != m_pDefaultpStr) 
	{
		delete[] m_pStr;
	}
}

MyString::MyString(const char * initStr)
{
	if (initStr != nullptr)
	{
		size_t length = strlen(initStr) + 1;

		m_pStr = new char[length];

		strcpy(m_pStr, initStr);
	}
	else
	{
		m_pStr = m_pDefaultpStr;
	}
}

MyString::MyString(const MyString & str)
{
	if (str.m_pStr != m_pDefaultpStr)
	{
		size_t length = strlen(str.m_pStr) + 1;

		m_pStr = new char[length];

		strcpy(m_pStr, str.m_pStr);
	}
	else
	{
		m_pStr = m_pDefaultpStr; 
	}
}

MyString::MyString(MyString && str)
{
	m_pStr = str.m_pStr; // твое - наше

	str.m_pStr = str.m_pDefaultpStr; // а у тебя теперь default
}

MyString & MyString::operator=(const char * initStr)
{
	if (initStr != nullptr && *initStr != 0)
	{
		if (m_pStr != m_pDefaultpStr)
		{
			delete[] m_pStr;
		}

		size_t length = strlen(initStr) + 1;

		m_pStr = new char[length];

		strcpy(m_pStr, initStr);
	}
	else
	{
		m_pStr = m_pDefaultpStr; 
	}

	return *this;
}

MyString & MyString::operator=(const MyString & str)
{
	if (&str != this)
	{
		if (m_pStr != m_pDefaultpStr)
		{
			delete[] m_pStr;
		}

		if (str.m_pStr != str.m_pDefaultpStr)
		{
			size_t length = strlen(str.m_pStr) + 1;

			m_pStr = new char[length];

			strcpy(m_pStr, str.m_pStr);
		}
		else
		{
			m_pStr = m_pDefaultpStr;
		}
	}

	return *this;
}

MyString & MyString::operator=(MyString && str)
{
	if (&str != this)
	{
		if (m_pStr != m_pDefaultpStr)
		{
			delete[] m_pStr;
		}
		m_pStr = str.m_pStr;
		str.m_pStr = str.m_pDefaultpStr;		
	}

	return *this;
}

// example

//bool MyString::operator>(const MyString & right) const
//{
//	for (size_t i = 0; i <= strlen(m_pStr); )
//	{
//		if (static_cast<unsigned char>(m_pStr[i]) < static_cast<unsigned char>(right.m_pStr[i]))
//		{
//			return true;
//		}
//		else if (static_cast<unsigned char>(m_pStr[i]) == static_cast<unsigned char>(right.m_pStr[i]))
//		{
//			++i;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	return true;	
//}

//another one

//bool MyString::operator>(const MyString & right) const
//{
//	for (size_t i = 0; i <= strlen(m_pStr); )
//	{
//		int result = static_cast<unsigned char>(m_pStr[i]) - static_cast<unsigned char>(right.m_pStr[i]);
//		if (result < 0)
//		{
//			return true;
//		}
//		else if (result == 0)
//		{
//			++i;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	return true;
//}

// last

bool MyString::operator>(const MyString & right) const
{
	char * my_m_pStr = m_pStr;
	char * right_m_pStr = right.m_pStr;

	while (*my_m_pStr == *right_m_pStr && *my_m_pStr != NULL)
	{
		++my_m_pStr;
		++right_m_pStr;
	}

	return (*my_m_pStr - *right_m_pStr) < 0;
}


bool MyString::operator<(const MyString & right) const
{
	for (size_t i = 0; i <= strlen(m_pStr); )
	{
		if (static_cast<unsigned char>(m_pStr[i]) < static_cast<unsigned char>(right.m_pStr[i]))
		{
			return false;
		}
		else if (static_cast<unsigned char>(m_pStr[i]) == static_cast<unsigned char>(right.m_pStr[i]))
		{
			++i;
		}
		else
		{
			return true;
		}
	}

	if (1)
	{
		return false;
	}
}

bool MyString::operator>=(const MyString & right) const
{
	for (size_t i = 0; i <= strlen(m_pStr); )
	{
		if (static_cast<unsigned char>(m_pStr[i]) < static_cast<unsigned char>(right.m_pStr[i]))
		{
			return true;
		}
		else if (static_cast<unsigned char>(m_pStr[i]) == static_cast<unsigned char>(right.m_pStr[i]))
		{
			++i;
		}
		else
		{
			return false;
		}
	}
	return true;	

	//вроде strcmp можно так сделать
}

bool MyString::operator<=(const MyString & right) const
{
	for (size_t i = 0; i <= strlen(m_pStr); )
	{
		if (static_cast<int>(m_pStr[i]) < static_cast<int>(right.m_pStr[i]))
		{
			return false;
		}
		else if (static_cast<int>(m_pStr[i]) == static_cast<int>(right.m_pStr[i]))
		{
			++i;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//MyString MyString::operator+(const MyString & str) //поплыл
//{
//	size_t leftlength = 0;
//	size_t rigthlength = 0;
//	size_t LENGTH;
//	if (str.m_pStr == str.m_pDefaultpStr)
//	{
//		return MyString();
//	}
//	else
//	{
//		rigthlength = strlen(str.m_pStr);
//		if (m_pStr != m_pDefaultpStr)
//		{
//			leftlength = strlen(m_pStr);
//			LENGTH = rigthlength + leftlength + 1;
//		}
//
//	}
//	
//}

std::ostream & operator<<(std::ostream & MYCOUT, const MyString & MYSTR)
{
	MYCOUT << MYSTR.m_pStr;
	return MYCOUT;
}
