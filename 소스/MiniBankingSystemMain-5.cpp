/*
	1. �ý��۸� : Banking System
	2. ��    �� : 2019.04.15 ~ 05.07
	3. Ver      : 1.3.4
	4. �����   : �̰���
	5. ���� ����
		Ver 1.3.4 :
			1. �迭Ŭ������ "Ŭ���� ���ø�"���� �����Ͽ� MiniBankingSystem�� ����.
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

		cout << "�޴� ���� : ";
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
			cout << "���α׷� ����\n";
			break;

		default:
			cout << "���� �޴��Դϴ�." << endl;
		}

		if (choice == QUIT) break;
	}

	return 0;
}

void Show_Account_MENU() // �޴����
{
	cout << "--------- Menu ---------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. ��ü�� �ܾ���ȸ" << endl;
	cout << "5. ���� ���̺�" << endl;
	cout << "6. ���� ���" << endl;
	cout << "7. ���α׷� ����" << endl;
}

void Show_OpenedAccount_Menu() // ���°��� ���ø޴�
{
	cout << "[ �������� ���� ]" << endl;
	cout << "1. ���뿹�ݰ���" << "   2. �ſ�ŷڰ���" << endl;
	cout << "���� >> ";
}

int Show_Credit_LEVEL_Menu() // �ſ��� ���ø޴�
{
	int choice;

	cout << "[ ���� �ſ��� ���� ]" << endl;
	cout << "LEVEL_A = 7" << "  LEVEL_B = 4" << "  LEVEL_C = 2" << endl;
	cout << "���� >> ";
	cin >> choice;
	cout << endl;

	if (choice != 7 && choice != 4 && choice != 2)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		return 0;
	}

	return choice;
}
