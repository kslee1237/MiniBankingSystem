#include "MiniBankingCommonDecl-5.h"
#include "NormalAccount-5.h"

// ������
NormalAccount::NormalAccount(const char *name, int numbers, double rate)
	: Cus_Account(name), NormalAccount_Numbers(numbers), NormalAccount_Balances(0)
	, Basic_RateOfInterest(rate)
{}

// �������� ���
void NormalAccount::Show_AccountInfo() const
{
	Show_AccountOfCus_Name();
	cout << "���¹�ȣ : " << NormalAccount_Numbers << endl;
	cout << "�⺻���� : " << GetBasic_Rate() << endl;
	cout << "�����ܾ� : " << NormalAccount_Balances << endl << endl;
}

// �⺻���� �������� �Լ�
double NormalAccount::GetBasic_Rate() const
{
	return Basic_RateOfInterest;
}

// Ư�� �����¹�ȣ ��ȸ
int NormalAccount::Find_Cus_Account() const
{
	return NormalAccount_Numbers;
}

// ���� �ܾ� �������� �Լ�
int NormalAccount::Get_CuurrentBalances() const
{
	return NormalAccount_Balances;
}

// �����ܾ� ����
void NormalAccount::Update_Account_Balances(int money, int account_nums, const char* acc_info)
{
	if (!strcmp(acc_info, ACCOUNT_INFO::DEPOSIT))
	{
		NormalAccount_Balances += money;
		Interest = (NormalAccount_Balances * GetBasic_Rate());

		NormalAccount_Balances += (int)Interest;
	}
	else if (!strcmp(acc_info, ACCOUNT_INFO::WITHDRAW))
	{
		if ((NormalAccount_Balances < money || NormalAccount_Balances < 0))
		{
			cout << "�ܾ��� �����մϴ�." << endl;
			getchar();
			return;
		}
		else
			NormalAccount_Balances -= money;
	}
}

// ����������� ���� ������ �������� �Լ���
char* NormalAccount::Get_accInfo()
{
	return accInfo;
}

int NormalAccount::Get_accnum()
{
	return NormalAccount_Numbers;
}

int NormalAccount::Get_balance()
{
	return NormalAccount_Balances;
}

double NormalAccount::Get_basicrate()
{
	return Basic_RateOfInterest;
}

int NormalAccount::Get_grade()
{
	return 1;
}

void NormalAccount::Update_AccBalanceByFile(int money)
{
	NormalAccount_Balances += money;
}