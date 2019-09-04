
#ifndef __ACCHDR_H_
#define __ACCHDR_H_

#include "Account-5.h"
#include "Classtemplate-5.h"

typedef Cus_Account *AccountPTR;

class Account_Handler
{
private:
	ArrayOfRange<AccountPTR> AccList; // �����¸���Ʈ
	int accNum;                       // ������ ��

public:	
	Account_Handler();              // ������

	int Get_accnum() const;         // �迭��Ұ��� ��ȯ
	void Open_An_Account(int sel);  // ���°����ϱ�
	void Deposit_Money();           // �����ϱ�
	void Withdraw_Money();          // ����ϱ�
	void Show_All_CusInfo() const;  // ��� ������ ��ȸ
	void FILE_LOAD();               // ���� �ҷ�����
	void FILE_BACKUP();             // ���� ���
	void FILE_SAVE();               // ���� ����
		
	~Account_Handler();             // �Ҹ���
};

#endif // !__ACCHDR_H_
