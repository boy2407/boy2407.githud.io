#include<iostream>
using namespace std;
void SeletionSort_DeQuy(int a[], int n, int i = 0)
{	
	if (i = n - 1)return;

	int vitri = 0;
	for (int j = i; j < n; ++j)
	{
		if (a[j] < a[vitri])vitri = j;
	}
	if (vitri != i)swap(a[vitri], a[i]);

	SeletionSort_DeQuy(a, n, i + 1);
}
void SeletionSort_DeQuy_2(int a[], int n)
{
	if (n == 1)
	{
		return;
	}
	int vitri = 0;
	for (int j = 1; j<n ; ++j)
	{
		if (a[j] < a[vitri])vitri = j;
	}
	swap(a[vitri], a[n - 1]);
	SeletionSort_DeQuy_2(a, n - 1);
}
void InterchangSort_DeQuy(int a[], int n, int i = 0)
{
	if (i = n - 1)return;
	for (int j = i; j < n; ++j)
	{
		if(a[j]<a[i])swap(a[j], a[i]);
	}
	InterchangSort_DeQuy(a, n, i + 1);
}
void InterchangSort_DeQuy_2(int a[], int n)
{
	if (n == 1)
	{
		return;
	}
	for (int j = 0; j < n; ++j)
	{
		if (a[j] < a[n-1])swap(a[j], a[n - 1]);;
	}
	InterchangSort_DeQuy_2(a, n - 1);
}
void BubbleSort_DeQuy(int a[], int n,int i=0)
{
	
	/*if (i == n - 1)return;*/
	bool check = true;
	for (int j = n - 1; j > i; --j)
	{
		if (a[j - 1] > a[j])
		{
			swap(a[j - 1], a[j]);
			check = false;
		}
	}
	if(check==false)
	BubbleSort_DeQuy(a, n, i + 1);
}
void BubbleSort_DeQuy2(int a[], int n)
{
	/*
	if (n == 1)
	{
		return;
	}*/
	bool check = true;
	for (int i = 0; i < n - 1; i++)
	{
		if(a[i]>a[i+1])
		{
			swap(a[i], a[i + 1]);
			check = false;
		}
	}
	if (n > 2&&check==false)
	BubbleSort_DeQuy2(a, n - 1);
}
int  main()
{

}