
#ifndef __Class_H__
#define __Class_H__

#include "MiniBankingCommonDecl-5.h"
#include "Exception-5.h"

template <typename CT> // 클래스 템플릿

class ArrayOfRange
{
private:
	CT *arr;
	int ArrLen;

	// 복사생성자
	ArrayOfRange(const ArrayOfRange &copy) {}

	// 대입연산자
	ArrayOfRange &operator =(const ArrayOfRange &arr) {}

public:		
	ArrayOfRange(int len = 10);      // 생성자
		
	CT &operator [] (int idx);       // 초기화 및 수정용	
	CT operator [] (int idx) const;  // 출력용	
	int Get_arrLen();                // 저장된 배열의 요소개수

	~ArrayOfRange();                 // 소멸자
};

// 생성자
template<typename CT>
ArrayOfRange<CT>::ArrayOfRange(int len) : ArrLen (len)
{	
	arr = new CT[len];	
}

// [] 연산자 오버로딩 : 초기화 및 수정용
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

// const [] 연산자 오버로딩 : 출력용
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

// 저장된 배열의 요소개수
template<typename CT>
int ArrayOfRange<CT>::Get_arrLen()
{
	return ArrLen;
}

// 소멸자
template<typename CT>
ArrayOfRange<CT>::~ArrayOfRange()
{
	delete[] arr;
}

#endif // !__Class_H__
