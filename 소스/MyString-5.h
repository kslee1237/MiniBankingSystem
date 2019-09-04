
#ifndef __MYSTRING_H__
#define __MYSTRING_H__

class MyString
{
private:
	char *str;  // ���ڿ� �迭�ּ�
	int strLen; // ���ڿ� ����

public:
	// ����Ʈ ������
	MyString() {}

	// �Ű������� �ִ� ������
	MyString(const char* str);

	// ���������
	MyString(const MyString &copy);

	char* Get_name() const;

	char* Get_name();

	MyString operator= (const MyString& str);

	// �Ҹ���
	~MyString();
};

#endif // !__MYSTRING_H__
