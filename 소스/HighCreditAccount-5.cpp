#include "MiniBankingCommonDecl-5.h"
#include "HighCreditAccount-5.h"

//  ������
HighCreditAccount::HighCreditAccount(const char* name, int numbers, double rate, int grade)
	: NormalAccount(name, (HighCreditAccount_Numbers = numbers), rate), CreditGrade(grade)
	, HighCreditAccount_Balances(0), Interest(0)
{
	// �ſ��޿� ���� �����߰�
	switch (grade)
	{
	case LEVEL_A:
		Ratio_ByCreditGrade = GetBasic_Rate() + 0.7;
		break;

	case LEVEL_B:
		Ratio_ByCreditGrade = GetBasic_Rate() + 0.4;
		break;

	case LEVEL_C:
		Ratio_ByCreditGrade = GetBasic_Rate() + 0.2;
		break;
	}
}

// �������� ���
void HighCreditAccount::Show_AccountInfo() const
{
	Show_AccountOfCus_Name();
	cout << "���¹�ȣ : " << HighCreditAccount_Numbers << endl;
	cout << "�⺻���� : " << GetBasic_Rate() << endl;
	cout << "�ſ��� : " << CreditGrade << endl;
	cout << "��    �� : " << Ratio_ByCreditGrade << endl;
	cout << "�����ܾ� : " << HighCreditAccount_Balances << endl << endl;
}

// Ư�� �����¹�ȣ ��ȸ
int HighCreditAccount::Find_Cus_Account() const
{
	return HighCreditAccount_Numbers;
}

// ���� �ܾ� �������� �Լ�
int HighCreditAccount::Get_CuurrentBalances() const
{
	return HighCreditAccount_Balances;
}

// HighCreditAccount �����ܾ� ����
void HighCreditAccount::Update_Account_Balances(int money, int account_nums, const char* acc_info)
{
	if (!strcmp(acc_info, ACCOUNT_INFO::DEPOSIT))
	{
		HighCreditAccount_Balances += money;
		Interest = (HighCreditAccount_Balances * Ratio_ByCreditGrade);

		HighCreditAccount_Balances += (int)Interest;
	}
	else if (!strcmp(acc_info, ACCOUNT_INFO::WITHDRAW))
	{
		if ((HighCreditAccount_Balances < money || HighCreditAccount_Balances < 0))
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			getchar();
			return;
		}
		else
			HighCreditAccount_Balances -= money;
	}
}

// ����������� ���� ������ �������� �Լ���
char* HighCreditAccount::Get_accInfo()
{
	return accInfo;
}

int HighCreditAccount::Get_accnum()
{
	return HighCreditAccount_Numbers;
}

int HighCreditAccount::Get_balance()
{
	return HighCreditAccount_Balances;
}

double HighCreditAccount::Get_basicrate()
{
	return GetBasic_Rate();
}

int HighCreditAccount::Get_grade()
{
	return CreditGrade;
}

void HighCreditAccount::Update_AccBalanceByFile(int money)
{
	HighCreditAccount_Balances += money;
}