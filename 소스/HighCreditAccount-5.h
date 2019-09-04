
#ifndef __HIGH_H__
#define __HIGH_H__

#include "NormalAccount-5.h"

class HighCreditAccount : public NormalAccount
{
private:
	int HighCreditAccount_Numbers;   // 고객 신용신뢰계좌번호
	int CreditGrade;                 // 신용등급
	double Ratio_ByCreditGrade;      // 신용등급에 따른 비율
	double Interest;                 // 이자
	int HighCreditAccount_Balances;  // 계좌잔액
	char accInfo[5] = "High";        // 파일입출력시 계좌종류 확인을 위한 변수

public:
	// 생성자
	HighCreditAccount(const char* name, int numbers, double rate, int grade);

	// 파일입출력을 위한 정보를 가져오는 함수들
	char* Get_accInfo();
	int Get_accnum();
	int Get_balance();
	double Get_basicrate();
	int Get_grade();
	void Update_AccBalanceByFile(int money);

	int Get_CuurrentBalances() const;            // 현재 잔액 가져오는 함수
	void Show_AccountInfo() const;               // 신용신뢰 계좌정보 출력
	int Find_Cus_Account() const;                // 특정 고객계좌번호 조회
	void Update_Account_Balances(int money,
		int account_nums, const char* acc_info); // 계좌잔액 갱신
};

#endif // !__HIGH_H__
