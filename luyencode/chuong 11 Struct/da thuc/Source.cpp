#include<iostream>
using namespace std;
struct  DaThuc
{
	int n;//so bac cao nhat cua da thức
	float* HeSo;
};

typedef struct DaThuc DATHUC;
void NhapDaThuc(DATHUC *&x)
{

	do
	{

		cout << "\nNhap vao so bac cua da thuc";
		cin >> x->n;
		
		if (x->n < 1)
		{
			cout << "\n so bac da thuc phai >=1";
		}
	} while (x->n <1);
	x->HeSo = new float[x->n + 1];
	for (int i = 0; i <= x->n; i++)
	{
		cout << "\Nhan He so X^" << i << "la";
		cin >> x->HeSo[i];
	}
}
void XuatDaThuc(DATHUC* x)
{
	cout << x->HeSo[0]<<"+";
	cout << x->HeSo[1] << "*X" <<" + ";
	for (int i = 2; i < x->n; i++)
	{
		cout << x->HeSo[i] << "*X^ " << i << " + ";
	}
	cout << x->HeSo[x->n] << "*X^ " << x->n ;
}
int main()
{
	DATHUC* x = new DATHUC;
	NhapDaThuc(x);
	XuatDaThuc(x);

	delete x;
}