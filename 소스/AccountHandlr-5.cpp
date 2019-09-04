
#include "MiniBankingCommonDecl-5.h"
#include "Exception-5.h"
#include "NormalAccount-5.h"
#include "HighCreditAccount-5.h"
#include "AccountHandlr-5.h"

// ������
Account_Handler::Account_Handler()
	: accNum(0)
{}

// �迭��Ұ��� ��ȯ
int Account_Handler::Get_accnum() const
{
	return accNum;
}

// �Ҹ���
Account_Handler::~Account_Handler()
{
	for (int j = 0; j < accNum; j++)
		delete AccList[j];
}

// ���°����ϱ�
void Account_Handler::Open_An_Account(int sel)
{
	char cus_name[20];
	int account_number;
	double basic_rateOfinterest;
	int Cus_CreditGrade;

	cout << "[ ���°��� ]" << endl;
	cout << "���� �Է� : ";
	cin >> cus_name;

	cout << "���¹�ȣ �Է� : ";
	cin >> account_number;

	cout << "�⺻���� �Է� : ";
	cin >> basic_rateOfinterest;

	cout << endl;

	if (accNum == 0) // ���� �� �� ���°�����
	{
		if (NORMAL == sel)
		{
			AccList[accNum] = new NormalAccount(cus_name, account_number,
				basic_rateOfinterest);
			
			AccList[accNum]->Show_AccountInfo();
			accNum++;

			cout << "���� ���� �Ϸ�" << endl;
			getchar();
			return;
		}
		else if (CREDIT == sel)
		{
			Cus_CreditGrade = Show_Credit_LEVEL_Menu();
			if (Cus_CreditGrade == 0) return;

			AccList[accNum] = new HighCreditAccount(cus_name, account_number,
					basic_rateOfinterest, Cus_CreditGrade);
			
			AccList[accNum]->Show_AccountInfo();
			accNum++;

			cout << "���� ���� �Ϸ�" << endl;
			getchar();
			return;
		}
	}
	else // �� ��°���� ���°�����
	{
		if (NORMAL == sel)
		{
			for (int j = 0; j < accNum; j++)
			{
				if (AccList[j]->Find_Cus_Account() == account_number)
				{
					cout << "��ϵǾ� �ִ� �����Դϴ�." << endl;
					getchar();
					return;
				}
			}

			AccList[accNum] = new NormalAccount(cus_name, account_number,
				basic_rateOfinterest);

			AccList[accNum]->Show_AccountInfo();
			accNum++;

			cout << "���� ���� �Ϸ�" << endl;
			getchar();
			return;
		}
		else if (CREDIT == sel)
		{
			for (int j = 0; j < accNum; j++)
			{
				if (AccList[j]->Find_Cus_Account() == account_number)
				{
					cout << "��ϵǾ� �ִ� �����Դϴ�." << endl;
					getchar();
					return;
				}
			}

			Cus_CreditGrade = Show_Credit_LEVEL_Menu();
			if (Cus_CreditGrade == 0) return;

			AccList[accNum] = new HighCreditAccount(cus_name, account_number,
				basic_rateOfinterest, Cus_CreditGrade);

			AccList[accNum]->Show_AccountInfo();
			accNum++;

			cout << "���� ���� �Ϸ�" << endl;
			getchar();
			return;			
		}
	}
}

// ��� ������ ��ȸ
void Account_Handler::Show_All_CusInfo() const
{
	for (int j = 0; j < accNum; j++)
		AccList[j]->Show_AccountInfo();

	getchar();
}

// �����ϱ�
void Account_Handler::Deposit_Money()
{
	int Account_number;
	int depos_money;

	cout << "[ �� �� ]" << endl;

	cout << "���¹�ȣ �Է� : ";
	cin >> Account_number;
	cout << endl;

	for (int j = 0; j < accNum; j++)
	{
		if (AccList[j]->Find_Cus_Account() == Account_number)
		{
			while (1)
			{
				cout << "�Ա��� �ݾ� �Է� : ";
				cin >> depos_money;
				cout << endl;

				try
				{
					if (depos_money < 0)
					{
						Values_Less_Than_Zero_Exception expn(depos_money);
						throw expn;
					}

					cout << "�ԱݿϷ�" << endl;

					AccList[j]->Update_Account_Balances(depos_money, Account_number,
						ACCOUNT_INFO::DEPOSIT);

					getchar();
					return;
				}
				catch (Values_Less_Than_Zero_Exception& expn)
				{
					expn.Show_Values_Less_Than_Zero_Exception();
				}
			}
		}
	}

	cout << "��ϵ��� �ʴ� �����Դϴ�." << endl;
	getchar();
}

// ����ϱ�
void Account_Handler::Withdraw_Money()
{
	int Account_number;
	int withdraw_money;

	cout << "[ �� �� ]" << endl;

	cout << "���¹�ȣ �Է� : ";
	cin >> Account_number;
	cout << endl;

	for (int j = 0; j < accNum; j++)
	{
		if (AccList[j]->Find_Cus_Account() == Account_number)
		{
			while (1)
			{
				cout << "����� �ݾ� �Է� : ";
				cin >> withdraw_money;
				cout << endl;

				try
				{
					if (withdraw_money < 0)
					{
						Values_Less_Than_Zero_Exception expn(withdraw_money);
						throw expn;
					}

					try
					{
						if (withdraw_money > AccList[j]->Get_CuurrentBalances())
						{
							Withdraw_Exception expn(withdraw_money);
							throw expn;
						}

						AccList[j]->Update_Account_Balances(withdraw_money, Account_number,
							ACCOUNT_INFO::WITHDRAW);

						cout << "��ݿϷ�" << endl;
						getchar();
						return;
					}
					catch (Withdraw_Exception& expn)
					{
						expn.Show_WithdrawException();
					}
				}
				catch (Values_Less_Than_Zero_Exception& expn)
				{
					expn.Show_Values_Less_Than_Zero_Exception();
				}
			}
		}
	}

	cout << "��ϵ��� �ʴ� �����Դϴ�." << endl;
	getchar();
}

FILE *fnormal;
FILE *fhighcredit;

// ���� �ҷ�����
void Account_Handler::FILE_LOAD()
{
	char nomal_accInfo[7];
	char high_accInfo[7];
	char name[20];
	int accnum = 0;
	int bal = 0;
	int grade = 0;
	double rateinterest = 0;

	int rnormal;
	int rhighcredit;

	fnormal = fopen("NomalAccList.txt", "r+");
	fhighcredit = fopen("HighcreditAccList.txt", "r+");

	if (fnormal == NULL) { cout << "���Ͽ��� ����" << endl; return; }
	if (fhighcredit == NULL) { cout << "���Ͽ��� ����" << endl; return; }

	for (int i = 0; i < ACCOUNT_INFO::FILE_MAX; i++)
	{
		rnormal = fscanf(fnormal, "%s %s %d %d %lf", nomal_accInfo, name, &accnum, &bal, &rateinterest);
		if (rnormal == EOF) break;
		
		if (!strcmp(ACCOUNT_INFO::NomalAccount, nomal_accInfo))
		{
			AccList[accNum] = new NormalAccount(name, accnum, rateinterest);
			AccList[accNum]->Update_AccBalanceByFile(bal);
			accNum++;
		}
	}
	
	fclose(fnormal);

	for (int i = 0; i < ACCOUNT_INFO::FILE_MAX; i++)
	{
		rhighcredit = fscanf(fhighcredit, "%s %s %d %d %lf %d", high_accInfo, name, &accnum, &grade,
			&rateinterest, &bal);
		if (rhighcredit == EOF) break;
		
		if (!strcmp(ACCOUNT_INFO::HighCreditAccount, high_accInfo))
		{
			AccList[accNum] = new HighCreditAccount(name, accnum, rateinterest, grade);
			AccList[accNum]->Update_AccBalanceByFile(bal);
			accNum++;
		}
	}

	fclose(fhighcredit);
}

// ���� ����
void  Account_Handler::FILE_SAVE()
{
	fnormal = fopen("NomalAccList.txt", "w+");

	for (int i = 0; i < accNum; i++)
	{
		if (!strcmp(ACCOUNT_INFO::NomalAccount, AccList[i]->Get_accInfo()))
		{
			fprintf(fnormal, "%s %s %d %d %lf\n", AccList[i]->Get_accInfo(),
				AccList[i]->GetName(), AccList[i]->Get_accnum(), AccList[i]->Get_balance(),
				AccList[i]->Get_basicrate());
		}
	}

	cout << "NomalAccountList ���� ���� �Ϸ�" << endl;
	fclose(fnormal);

	fhighcredit = fopen("HighcreditAccList.txt", "w+");

	for (int j = 0; j < accNum; j++)
	{
		if (!strcmp(ACCOUNT_INFO::HighCreditAccount, AccList[j]->Get_accInfo()))
		{
			fprintf(fhighcredit, "%s %s %d %d %lf %d\n", AccList[j]->Get_accInfo(),
				AccList[j]->GetName(), AccList[j]->Get_accnum(), AccList[j]->Get_grade(), 
				AccList[j]->Get_basicrate(), AccList[j]->Get_balance());
		}
	}

	cout << "HighcreditAccountList ���� ���� �Ϸ�" << endl;
	fclose(fhighcredit);
}

// ���� ���
void  Account_Handler::FILE_BACKUP()
{
	fnormal = fopen("Backup_NomalAccList.txt", "w+");

	for (int i = 0; i < accNum; i++)
	{
		if (!strcmp(ACCOUNT_INFO::NomalAccount, AccList[i]->Get_accInfo()))
		{
			fprintf(fnormal, "%s %s %d %d %lf\n", AccList[i]->Get_accInfo(),
				AccList[i]->GetName(), AccList[i]->Get_accnum(), AccList[i]->Get_balance(),
				AccList[i]->Get_basicrate());
		}
	}

	cout << "NomalAccountList ���� ��� �Ϸ�" << endl;
	fclose(fnormal);

	fhighcredit = fopen("Backup_HighcreditAccList.txt", "w+");

	for (int j = 0; j < accNum; j++)
	{
		if (!strcmp(ACCOUNT_INFO::HighCreditAccount, AccList[j]->Get_accInfo()))
		{
			fprintf(fhighcredit, "%s %s %d %d %lf %d\n", AccList[j]->Get_accInfo(), AccList[j]->GetName(),
				AccList[j]->Get_accnum(), AccList[j]->Get_grade(), AccList[j]->Get_basicrate(),
				AccList[j]->Get_balance());
		}
	}
	
	cout << "HighcreditAccountList ���� ��� �Ϸ�" << endl;
	fclose(fhighcredit);
}
