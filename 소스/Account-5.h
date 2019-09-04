
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "MyString-5.h"

class Cus_Account
{
private:
	MyString Name; // ���̸�

public:
	// ������
	Cus_Account(const char *name);

	// ���������
	Cus_Account(const Cus_Account &copy);

	// �̸� �������� �Լ�
	char* GetName() const;

	// ����������� ���� ������ �������� �Լ�
	char* GetName();
	virtual char* Get_accInfo() = 0;
	virtual int Get_accnum() = 0;
	virtual int Get_balance() = 0;
	virtual double Get_basicrate() = 0;
	virtual int Get_grade() = 0;
	virtual void Update_AccBalanceByFile(int money) = 0;
	 
	void Show_AccountOfCus_Name() const;             // ���̸� ���
	virtual int Get_CuurrentBalances() const = 0;    // ���� �ܾ� �������� �Լ�
	virtual void Show_AccountInfo() const = 0;       // �������� ���
	virtual int Find_Cus_Account() const = 0;        // Ư�� �����¹�ȣ ��ȸ
	virtual void Update_Account_Balances(int money,
		int account_nums, const char* acc_info) = 0; // �����ܾ� ����
};

#endif // !__ACCOUNT_H__
