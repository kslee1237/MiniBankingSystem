
#ifndef __HIGH_H__
#define __HIGH_H__

#include "NormalAccount-5.h"

class HighCreditAccount : public NormalAccount
{
private:
	int HighCreditAccount_Numbers;   // �� �ſ�ŷڰ��¹�ȣ
	int CreditGrade;                 // �ſ���
	double Ratio_ByCreditGrade;      // �ſ��޿� ���� ����
	double Interest;                 // ����
	int HighCreditAccount_Balances;  // �����ܾ�
	char accInfo[5] = "High";        // ��������½� �������� Ȯ���� ���� ����

public:
	// ������
	HighCreditAccount(const char* name, int numbers, double rate, int grade);

	// ����������� ���� ������ �������� �Լ���
	char* Get_accInfo();
	int Get_accnum();
	int Get_balance();
	double Get_basicrate();
	int Get_grade();
	void Update_AccBalanceByFile(int money);

	int Get_CuurrentBalances() const;            // ���� �ܾ� �������� �Լ�
	void Show_AccountInfo() const;               // �ſ�ŷ� �������� ���
	int Find_Cus_Account() const;                // Ư�� �����¹�ȣ ��ȸ
	void Update_Account_Balances(int money,
		int account_nums, const char* acc_info); // �����ܾ� ����
};

#endif // !__HIGH_H__
