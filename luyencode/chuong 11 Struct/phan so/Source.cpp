#include<iostream>
using namespace std;
struct  Phanso
{
	int Tuso, Mauso;
};
typedef struct Phanso PHANSO;
void nhapPhanSo(PHANSO& ps)
{
	cout << "\nNhap vao tu so: ";
	cin >> ps.Tuso;

	do
	{
		
		cout << "\nNhap mau so: ";
		cin >> ps.Mauso;
		if (ps.Mauso == 0)
		{
			cout << "\nVui long nhap lai";
		}
	} while (ps.Mauso==0);
}
void XuatPhanSo(PHANSO ps )
{
	cout << ps.Tuso << "/" << ps.Mauso;
}
PHANSO TinhTong(PHANSO ps1, PHANSO ps2)
{
	PHANSO Temp;
	Temp.Tuso = ps1.Tuso * ps2.Mauso + ps2.Tuso * ps1.Mauso;
	Temp.Mauso = ps1.Mauso * ps2.Mauso;
	return Temp;
}
int TimUCNL(int a, int b)
{
	if (a == 0 && b != 0)
		return b;
	if (b == 0 && a != 0)
		return a;

	if (a < 0)
		a *= -1;

	if (b < 0)
		b *= -1;

	while (a!=b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
}
void RutGonPhanSo(PHANSO &ps)
{
	int temp = TimUCNL(ps.Tuso, ps.Mauso);
	ps.Tuso = ps.Tuso / temp;
	ps.Mauso = ps.Mauso / temp;
}
PHANSO operator+(PHANSO ps1, PHANSO ps2)
{
	PHANSO Temp;
	Temp.Tuso = ps1.Tuso * ps2.Mauso + ps2.Tuso * ps1.Mauso;
	Temp.Mauso = ps1.Mauso * ps2.Mauso;
	return Temp;
	
}
istream& operator>>(istream& is, PHANSO& ps)
{

	cout << "\nNhap vao tu so: ";
	is >> ps.Tuso;

	do
	{

		cout << "\nNhap mau so: ";
		cin >> ps.Mauso;
		if (ps.Mauso == 0)
		{
			cout << "\nVui long nhap lai";
		}
	} while (ps.Mauso == 0);
	return is;
}
ostream& operator<<(ostream& os, PHANSO ps)
{	os << ps.Tuso << "/" << ps.Mauso;
	return os;
}
int main()
{
	PHANSO ps1,ps2,ps3;
	nhapPhanSo(ps1);
	cout << TimUCNL(ps1.Tuso, ps1.Mauso)<<"\n";
	RutGonPhanSo(ps1);
	XuatPhanSo(ps1);
	nhapPhanSo(ps2);
	nhapPhanSo(ps3);
	PHANSO tong = ps1 + ps2 + ps3;
	XuatPhanSo(tong);
}