#include "MiniBankingCommonDecl-5.h"
#include "Exception-5.h"

/* Withdraw_Exception */
Withdraw_Exception::Withdraw_Exception(int money) : withdraw_money(money)
{}

void Withdraw_Exception::Show_WithdrawException() const
{
	cout << "���� �޽��� : �ܾ׺���!! '" << withdraw_money << "'�� ����� �� �����ϴ�." << endl;
}

/* Values_Less_Than_Zero_Exception */
Values_Less_Than_Zero_Exception::Values_Less_Than_Zero_Exception(int cash) : money(cash)
{}

void Values_Less_Than_Zero_Exception::Show_Values_Less_Than_Zero_Exception() const
{
	cout << "���� �޽��� : '" << money << "' -> 0���� ���� �ݾ��� �Է��� �� �����ϴ�." << endl;
	cout << "�ٽ� �����Ͻʽÿ�" << endl;
}

/* Array_Out_of_Range_Exception */
Array_Out_of_Range_Exception::Array_Out_of_Range_Exception(int cnt) : count(cnt)
{}

void Array_Out_of_Range_Exception::Show_Array_Out_of_Range_Exception() const
{
	cout << "���� �޽��� : '" << count << "' -> �迭�� ������ ������ϴ�." << endl;
	cout << "��������� �� �̻� ������ �����ϴ�.!!" << endl;
}