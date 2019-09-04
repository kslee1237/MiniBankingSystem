#include "MiniBankingCommonDecl-5.h"
#include "Account-5.h"

// 생성자
Cus_Account::Cus_Account(const char *name)
{
	Name = MyString(name);
}

// 복사생성자
Cus_Account::Cus_Account(const Cus_Account &copy)
{
	Name = copy.Name;
}

// 이름 가져오는 함수
char* Cus_Account::GetName() const
{
	return Name.Get_name();
}

// 파일입출력을 위한 정보를 가져오는 함수
	// 이름 가져오는 함수
char* Cus_Account::GetName() 
{ return Name.Get_name(); }

// 고객이름 출력
void Cus_Account::Show_AccountOfCus_Name() const
{ 
	cout << "[ " << Name.Get_name() << "의 계좌정보 ] " << endl; 
}
