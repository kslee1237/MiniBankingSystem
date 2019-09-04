
#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

class Withdraw_Exception
{
private:
	int withdraw_money; // 출금액

public:
	Withdraw_Exception(int money);
	void Show_WithdrawException() const;
};

class Values_Less_Than_Zero_Exception
{
private:
	int money; // 예금 또는 출금액

public:
	Values_Less_Than_Zero_Exception(int cash);
	void Show_Values_Less_Than_Zero_Exception() const;
};

class Array_Out_of_Range_Exception
{
private:
	int count; // 배열클래스의 요소개수

public:
	Array_Out_of_Range_Exception(int cnt);
	void Show_Array_Out_of_Range_Exception() const;
};

#endif // !__EXCEPTION_H__
