
#ifndef __MYSTRING_H__
#define __MYSTRING_H__

class MyString
{
private:
	char *str;  // 문자열 배열주소
	int strLen; // 문자열 길이

public:
	// 디폴트 생성자
	MyString() {}

	// 매개변수가 있는 생성자
	MyString(const char* str);

	// 복사생성자
	MyString(const MyString &copy);

	char* Get_name() const;

	char* Get_name();

	MyString operator= (const MyString& str);

	// 소멸자
	~MyString();
};

#endif // !__MYSTRING_H__
