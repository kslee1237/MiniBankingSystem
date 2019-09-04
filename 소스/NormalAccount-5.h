
#ifndef __NOMAL_H__
#define __NOMAL_H__

#include "Account-5.h"

class NormalAccount : public Cus_Account
{
private:
	int NormalAccount_Numbers;   // �� ���뿹�ݰ��¹�ȣ
	int NormalAccount_Balances;  // �����ܾ�
	double Basic_RateOfInterest; // �⺻����
	double Interest;             // ����
	char accInfo[6] = "Nomal";   // ��������½� �������� Ȯ���� ���� ����

public:
	// ������
	NormalAccount(const char *name, int numbers, double rate);

	// ����������� ���� ������ �������� �Լ���
	char* Get_accInfo();
	int Get_accnum();
	int Get_balance();
	double Get_basicrate();
	int Get_grade();
	void Update_AccBalanceByFile(int money);

	int Get_CuurrentBalances() const;            // ���� �ܾ� �������� �Լ�
	void Show_AccountInfo() const;               // ���뿹�� �������� ���
	double GetBasic_Rate() const;                // �⺻���� �������� �Լ�	
	int Find_Cus_Account() const;                // Ư�� �����¹�ȣ ��ȸ
	void Update_Account_Balances(int money,
		int account_nums, const char* acc_info); // �����ܾ� ����
};

#endif // !__NOMAL_H__
