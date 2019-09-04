#include "MiniBankingCommonDecl-5.h"
#include "MyString-5.h"

// �Ű������� �ִ� ������
MyString::MyString(const char* str)
{
	strLen = strlen(str) + 1;
	this->str = new char[strLen];
	strcpy(this->str, str);
}

// ���������
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

// �Ҹ���
MyString::~MyString()
{
	delete[] str;
}