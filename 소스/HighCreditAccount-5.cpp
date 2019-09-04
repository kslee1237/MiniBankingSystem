#include "MiniBankingCommonDecl-5.h"
#include "HighCreditAccount-5.h"

//  생성자
HighCreditAccount::HighCreditAccount(const char* name, int numbers, double rate, int grade)
	: NormalAccount(name, (HighCreditAccount_Numbers = numbers), rate), CreditGrade(grade)
	, HighCreditAccount_Balances(0), Interest(0)
{
	// 신용등급에 따른 이율추가
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

// 계좌정보 출력
void HighCreditAccount::Show_AccountInfo() const
{
	Show_AccountOfCus_Name();
	cout << "계좌번호 : " << HighCreditAccount_Numbers << endl;
	cout << "기본이율 : " << GetBasic_Rate() << endl;
	cout << "신용등급 : " << CreditGrade << endl;
	cout << "이    율 : " << Ratio_ByCreditGrade << endl;
	cout << "계좌잔액 : " << HighCreditAccount_Balances << endl << endl;
}

// 특정 고객계좌번호 조회
int HighCreditAccount::Find_Cus_Account() const
{
	return HighCreditAccount_Numbers;
}

// 현재 잔액 가져오는 함수
int HighCreditAccount::Get_CuurrentBalances() const
{
	return HighCreditAccount_Balances;
}

// HighCreditAccount 계좌잔액 갱신
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
			cout << "잔액이 부족합니다." << endl;
			getchar();
			return;
		}
		else
			HighCreditAccount_Balances -= money;
	}
}

// 파일입출력을 위한 정보를 가져오는 함수들
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