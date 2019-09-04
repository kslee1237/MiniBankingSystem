#include "MiniBankingCommonDecl-5.h"
#include "MyString-5.h"

// 매개변수가 있는 생성자
MyString::MyString(const char* str)
{
	strLen = strlen(str) + 1;
	this->str = new char[strLen];
	strcpy(this->str, str);
}

// 복사생성자
MyString::MyString(const MyString &copy)
{
	this->strLen = copy.strLen;
	this->str = new char[this->strLen];
	strcpy(this->str, copy.str);
}

char* MyString::Get_name() const
{
	return this->str;
}

char* MyString::Get_name()
{
	return str;
}

MyString MyString::operator= (const MyString& str)
{
	this->strLen = str.strLen;
	this->str = new char[this->strLen];
	strcpy(this->str, str.str);

	return *this;
}

// 소멸자
MyString::~MyString()
{
	delete[] str;
}