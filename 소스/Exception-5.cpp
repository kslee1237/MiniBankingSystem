#include "MiniBankingCommonDecl-5.h"
#include "Exception-5.h"

/* Withdraw_Exception */
Withdraw_Exception::Withdraw_Exception(int money) : withdraw_money(money)
{}

void Withdraw_Exception::Show_WithdrawException() const
{
	cout << "예외 메시지 : 잔액부족!! '" << withdraw_money << "'는 출금할 수 없습니다." << endl;
}

/* Values_Less_Than_Zero_Exception */
Values_Less_Than_Zero_Exception::Values_Less_Than_Zero_Exception(int cash) : money(cash)
{}

void Values_Less_Than_Zero_Exception::Show_Values_Less_Than_Zero_Exception() const
{
	cout << "예외 메시지 : '" << money << "' -> 0보다 적은 금액은 입력할 수 없습니다." << endl;
	cout << "다시 실행하십시오" << endl;
}

/* Array_Out_of_Range_Exception */
Array_Out_of_Range_Exception::Array_Out_of_Range_Exception(int cnt) : count(cnt)
{}

void Array_Out_of_Range_Exception::Show_Array_Out_of_Range_Exception() const
{
	cout << "예외 메시지 : '" << count << "' -> 배열의 범위를 벗어났습니다." << endl;
	cout << "저장공간에 더 이상 여유가 없습니다.!!" << endl;
}