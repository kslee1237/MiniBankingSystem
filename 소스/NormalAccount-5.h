
#ifndef __NOMAL_H__
#define __NOMAL_H__

#include "Account-5.h"

class NormalAccount : public Cus_Account
{
private:
	int NormalAccount_Numbers;   // 고객 보통예금계좌번호
	int NormalAccount_Balances;  // 계좌잔액
	double Basic_RateOfInterest; // 기본이율
	double Interest;             // 이자
	char accInfo[6] = "Nomal";   // 파일입출력시 계좌종류 확인을 위한 변수

public:
	// 생성자
	NormalAccount(const char *name, int numbers, double rate);

	// 파일입출력을 위한 정보를 가져오는 함수들
	char* Get_accInfo();
	int Get_accnum();
	int Get_balance();
	double Get_basicrate();
	int Get_grade();
	void Update_AccBalanceByFile(int money);

	int Get_CuurrentBalances() const;            // 현재 잔액 가져오는 함수
	void Show_AccountInfo() const;               // 보통예금 계좌정보 출력
	double GetBasic_Rate() const;                // 기본이율 가져오는 함수	
	int Find_Cus_Account() const;                // 특정 고객계좌번호 조회
	void Update_Account_Balances(int money,
		int account_nums, const char* acc_info); // 계좌잔액 갱신
};

#endif // !__NOMAL_H__
