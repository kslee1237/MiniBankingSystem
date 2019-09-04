
#ifndef __ACCHDR_H_
#define __ACCHDR_H_

#include "Account-5.h"
#include "Classtemplate-5.h"

typedef Cus_Account *AccountPTR;

class Account_Handler
{
private:
	ArrayOfRange<AccountPTR> AccList; // 고객계좌리스트
	int accNum;                       // 고객계좌 수

public:	
	Account_Handler();              // 생성자

	int Get_accnum() const;         // 배열요소개수 반환
	void Open_An_Account(int sel);  // 계좌개설하기
	void Deposit_Money();           // 예금하기
	void Withdraw_Money();          // 출금하기
	void Show_All_CusInfo() const;  // 모든 고객정보 조회
	void FILE_LOAD();               // 파일 불러오기
	void FILE_BACKUP();             // 파일 백업
	void FILE_SAVE();               // 파일 저장
		
	~Account_Handler();             // 소멸자
};

#endif // !__ACCHDR_H_
