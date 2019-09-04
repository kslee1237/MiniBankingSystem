#include "MiniBankingCommonDecl-5.h"
#include "NormalAccount-5.h"

// 생성자
NormalAccount::NormalAccount(const char *name, int numbers, double rate)
	: Cus_Account(name), NormalAccount_Numbers(numbers), NormalAccount_Balances(0)
	, Basic_RateOfInterest(rate)
{}

// 계좌정보 출력
void NormalAccount::Show_AccountInfo() const
{
	Show_AccountOfCus_Name();
	cout << "계좌번호 : " << NormalAccount_Numbers << endl;
	cout << "기본이율 : " << GetBasic_Rate() << endl;
	cout << "계좌잔액 : " << NormalAccount_Balances << endl << endl;
}

// 기본이율 가져오는 함수
double NormalAccount::GetBasic_Rate() const
{
	return Basic_RateOfInterest;
}

// 특정 고객계좌번호 조회
int NormalAccount::Find_Cus_Account() const
{
	return NormalAccount_Numbers;
}

// 현재 잔액 가져오는 함수
int NormalAccount::Get_CuurrentBalances() const
{
	return NormalAccount_Balances;
}

// 계좌잔액 갱신
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
			cout << "잔액이 부족합니다." << endl;
			getchar();
			return;
		}
		else
			NormalAccount_Balances -= money;
	}
}

// 파일입출력을 위한 정보를 가져오는 함수들
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