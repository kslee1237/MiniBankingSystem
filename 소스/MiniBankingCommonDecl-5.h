
#ifndef __MINI_H__
#define __MINI_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

namespace ACCOUNT_INFO
{
	static const int FILE_MAX = 50;
	static const char* NomalAccount = "Nomal";
	static const char* HighCreditAccount = "High";
	static const char* DEPOSIT = "DEPOSIT";
	static const char* WITHDRAW = "WITHDRAW";
}

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQURIE, SAVE, BACKUP, QUIT }; // 메뉴관련 열거자
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };                    // 신용등급
enum { NORMAL = 1, CREDIT = 2 };                                   // 계좌의 종류

void Show_Account_MENU();       // 메뉴출력
void Show_OpenedAccount_Menu(); // 계좌개설 선택메뉴
int Show_Credit_LEVEL_Menu();   // 신용등급 선택메뉴

#endif // __MINI_H__
