
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

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQURIE, SAVE, BACKUP, QUIT }; // �޴����� ������
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };                    // �ſ���
enum { NORMAL = 1, CREDIT = 2 };                                   // ������ ����

void Show_Account_MENU();       // �޴����
void Show_OpenedAccount_Menu(); // ���°��� ���ø޴�
int Show_Credit_LEVEL_Menu();   // �ſ��� ���ø޴�

#endif // __MINI_H__
