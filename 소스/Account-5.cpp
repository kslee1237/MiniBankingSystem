#include "MiniBankingCommonDecl-5.h"
#include "Account-5.h"

// ������
Cus_Account::Cus_Account(const char *name)
{
	Name = MyString(name);
}

// ���������
Cus_Account::Cus_Account(const Cus_Account &copy)
{
	Name = copy.Name;
}

// �̸� �������� �Լ�
char* Cus_Account::GetName() const
{
	return Name.Get_name();
}

// ����������� ���� ������ �������� �Լ�
	// �̸� �������� �Լ�
char* Cus_Account::GetName() 
{ return Name.Get_name(); }

// ���̸� ���
void Cus_Account::Show_AccountOfCus_Name() const
{ 
	cout << "[ " << Name.Get_name() << "�� �������� ] " << endl; 
}
