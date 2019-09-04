/*
	1. 시스템명 : Banking System
	2. 일    자 : 2019.04.15 ~ 05.07
	3. Ver      : 1.3.4
	4. 담당자   : 이강산
	5. 버전 내용
		Ver 1.3.4 :
			1. 배열클래스를 "클래스 템플릿"으로 변경하여 MiniBankingSystem에 적용.
*/

#include "AccountHandlr-5.h"

int main(void)
{	
	Account_Handler accHdr;

	accHdr.FILE_LOAD();
	int choice;

	while (true)
	{
		Show_Account_MENU();

		cout << "메뉴 선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			int sel;
			Show_OpenedAccount_Menu();
			cin >> sel;
			cout << endl;

			accHdr.Open_An_Account(sel);
			break;

		case DEPOSIT:
			accHdr.Deposit_Money();
			break;

		case WITHDRAW:
			accHdr.Withdraw_Money();
			break;

		case INQURIE:
			accHdr.Show_All_CusInfo();
			break;

		case SAVE:
			accHdr.FILE_SAVE();
			break;

		case BACKUP:
			accHdr.FILE_BACKUP();
			break;

		case QUIT:
			cout << "프로그램 종료\n";
			break;

		default:
			cout << "없는 메뉴입니다." << endl;
		}

		if (choice == QUIT) break;
	}

	return 0;
}

void Show_Account_MENU() // 메뉴출력
{
	cout << "--------- Menu ---------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체고객 잔액조회" << endl;
	cout << "5. 파일 세이브" << endl;
	cout << "6. 파일 백업" << endl;
	cout << "7. 프로그램 종료" << endl;
}

void Show_OpenedAccount_Menu() // 계좌개설 선택메뉴
{
	cout << "[ 계좌종류 선택 ]" << endl;
	cout << "1. 보통예금계좌" << "   2. 신용신뢰계좌" << endl;
	cout << "선택 >> ";
}

int Show_Credit_LEVEL_Menu() // 신용등급 선택메뉴
{
	int choice;

	cout << "[ 고객의 신용등급 선택 ]" << endl;
	cout << "LEVEL_A = 7" << "  LEVEL_B = 4" << "  LEVEL_C = 2" << endl;
	cout << "선택 >> ";
	cin >> choice;
	cout << endl;

	if (choice != 7 && choice != 4 && choice != 2)
	{
		cout << "잘못 입력하셨습니다." << endl;
		return 0;
	}

	return choice;
}
