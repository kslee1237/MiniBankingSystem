
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

class Withdraw_Exception
{
private:
	int withdraw_money; // ��ݾ�

public:
	Withdraw_Exception(int money);
	void Show_WithdrawException() const;
};

class Values_Less_Than_Zero_Exception
{
private:
	int money; // ���� �Ǵ� ��ݾ�

public:
	Values_Less_Than_Zero_Exception(int cash);
	void Show_Values_Less_Than_Zero_Exception() const;
};

class Array_Out_of_Range_Exception
{
private:
	int count; // �迭Ŭ������ ��Ұ���

public:
	Array_Out_of_Range_Exception(int cnt);
	void Show_Array_Out_of_Range_Exception() const;
};

#endif // !__EXCEPTION_H__
