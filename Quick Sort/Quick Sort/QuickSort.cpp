#include <stdio.h>
#include "QuickSort.h"

/*****************************************
��������Median3()
���ܣ�������ֵ�ָ��ȡһ�����ʵĻ�׼ֵ
*****************************************/
int Median3(int A[], int Left, int Right)
{
	int Center = (Left+Right)/2;

	if (A[Left] > A[Center])
	{
		Swap(&A[Left],&A[Center]);
	}
	if(A[Left] > A[Right])
	{
		Swap(&A[Left],&A[Right]);
	}
	if(A[Center] > A[Right])
	{
		Swap(&A[Center],&A[Right]);
	}

	Swap(&A[Center],&A[Left]);
	return A[Left];
}

/*******************************
��������Swap()
���ܣ�����num1��num2��ֵ
*******************************/
void Swap(int* num1,int* num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
/****************************************
���������Partuition�㷨
****************************************/
int Partition(int A[],int Left,int Right)
{
	int i,j;
	int Pivot;
	i = Left;j = Right;
	Pivot = Median3(A,Left,Right);
	//Pivot = A[Left];
	while(i<j)
	{
		while(i<j && A[j] >= Pivot)
			--j;
		while(i<j && A[i] <= Pivot)
			++i;
		
		if(i<j) 
			Swap(&A[i],&A[j]);
	}
	Swap(&A[Left],&A[i]);
	return i;
}

/*********************************************
��������Qsort()
���룺A[]������Ҫ���������
	  Left����������߽��±�
	  Right���������ұ߽��±�
�������
���ܣ���������
*********************************************/
void Qsort(int A[],int Left,int Right)
{
	int i;
	if(Left<Right)
	{
		i = Partition(A,Left,Right);
		Qsort(A,Left,i-1);
		Qsort(A,i+1,Right);
	}
}


int main()
{
	int i,len;
	int A[] = {2,6,3,8,1,9,4,211,57,489,34,25,13,89,55,32,41,98,40,12,41,21,78,999,56,443,267,23};
	//int A[5] = {3,5,1,4,2};
	len = sizeof(A)/sizeof(int);
	Qsort(A,0,len-1);
	for(i=0; i<len; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}