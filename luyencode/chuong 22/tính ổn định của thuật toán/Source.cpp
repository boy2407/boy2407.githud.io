#include<iostream>
#include<string>
#include<time.h>
using namespace std;
struct HocSinh
{
	string Ten;
	int Diem;
	int index;
};
typedef struct HocSinh HOCSINH;
void PhatsinhDanhSachHocSinh(HOCSINH *&a, int& n)
{
	cout << "\nNhap vao so luong hoc sinh";
	cin >> n;
	srand(time(0));
	a = new HOCSINH[n];
	for (int i = 0; i < n; ++i)
	{
		a[i].index = i;
		a[i].Diem = rand() % 11;

		int vetraiTen = (i + 1) / 26;
		int vephaiTen = (i + 1) % 26;
		if (vephaiTen == 0)
		{
			--vetraiTen;
			for (int j = 1; j <= vetraiTen; ++j)
			{
				a[i].Ten += 'A';
			}		
				a[i].Ten += 'Z';			
		}
		else 
		{
			for (int j = 1; j <= vetraiTen; ++j)
			{
				a[i].Ten += 'A';
			}
			a[i].Ten += char(64 + vephaiTen);
		}
		
	}

}
void XuatDanhSach(HOCSINH* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i].Ten << "\t" << a[i].Diem << endl;
	}
}
void HoanVi(HOCSINH & a,HOCSINH& b)
{
	HOCSINH temp = a; a = b; b = temp;
	
}
void SelectionSort(HOCSINH* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int vitrimax = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j].Diem > a[vitrimax].Diem)
			{
				vitrimax = j;
			}
			else if(a[j].Diem == a[vitrimax].Diem)
			{
				if (a[j].index < a[vitrimax].index)
					vitrimax = j;
			}
		}
		swap(a[i], a[vitrimax]);
	}
}
int main()
{
	HOCSINH* a;
	int n;
	PhatsinhDanhSachHocSinh(a, n);
	XuatDanhSach(a, n);
	cout << "\nDa sap Xep\n";
	SelectionSort(a, n);
	XuatDanhSach(a, n);
	delete[]a;
	
	system("pause");
	return 0;
}