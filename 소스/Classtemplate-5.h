
#ifndef __Class_H__
#define __Class_H__

#include "MiniBankingCommonDecl-5.h"
#include "Exception-5.h"

template <typename CT> // Ŭ���� ���ø�

class ArrayOfRange
{
private:
	CT *arr;
	int ArrLen;

	// ���������
	ArrayOfRange(const ArrayOfRange &copy) {}

	// ���Կ�����
	ArrayOfRange &operator =(const ArrayOfRange &arr) {}

public:		
	ArrayOfRange(int len = 10);      // ������
		
	CT &operator [] (int idx);       // �ʱ�ȭ �� ������	
	CT operator [] (int idx) const;  // ��¿�	
	int Get_arrLen();                // ����� �迭�� ��Ұ���

	~ArrayOfRange();                 // �Ҹ���
};

// ������
template<typename CT>
ArrayOfRange<CT>::ArrayOfRange(int len) : ArrLen (len)
{	
	arr = new CT[len];	
}

// [] ������ �����ε� : �ʱ�ȭ �� ������
template<typename CT>
CT& ArrayOfRange<CT>::operator [] (int idx)
{
	try
	{
		if (idx < 0 || idx >= ArrLen)
		{
			Array_Out_of_Range_Exception expn(idx);
			throw expn;
		}

		return arr[idx];
	}
	catch (Array_Out_of_Range_Exception& expn)
	{
		expn.Show_Array_Out_of_Range_Exception();
		exit(1);
	}
}

// const [] ������ �����ε� : ��¿�
template<typename CT>
CT ArrayOfRange<CT>::operator [] (int idx) const
{
	try
	{
		if (idx < 0 || idx >= ArrLen)
		{
			Array_Out_of_Range_Exception expn(idx);
			throw expn;
		}

		return arr[idx];
	}
	catch (Array_Out_of_Range_Exception& expn)
	{
		expn.Show_Array_Out_of_Range_Exception();
		exit(1);
	}
}

// ����� �迭�� ��Ұ���
template<typename CT>
int ArrayOfRange<CT>::Get_arrLen()
{
	return ArrLen;
}

// �Ҹ���
template<typename CT>
ArrayOfRange<CT>::~ArrayOfRange()
{
	delete[] arr;
}

#endif // !__Class_H__
