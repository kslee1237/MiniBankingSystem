
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "MyString-5.h"

class Cus_Account
{
private:
	MyString Name; // 고객이름

public:
	// 생성자
	Cus_Account(const char *name);

	// 복사생성자
	Cus_Account(const Cus_Account &copy);

	// 이름 가져오는 함수
	char* GetName() const;

	// 파일입출력을 위한 정보를 가져오는 함수
	char* GetName();
	virtual char* Get_accInfo() = 0;
	virtual int Get_accnum() = 0;
	virtual int Get_balance() = 0;
	virtual double Get_basicrate() = 0;
	virtual int Get_grade() = 0;
	virtual void Update_AccBalanceByFile(int money) = 0;
	 
	void Show_AccountOfCus_Name() const;             // 고객이름 출력
	virtual int Get_CuurrentBalances() const = 0;    // 현재 잔액 가져오는 함수
	virtual void Show_AccountInfo() const = 0;       // 계좌정보 출력
	virtual int Find_Cus_Account() const = 0;        // 특정 고객계좌번호 조회
	virtual void Update_Account_Balances(int money,
		int account_nums, const char* acc_info) = 0; // 계좌잔액 갱신
};

#endif // !__ACCOUNT_H__
