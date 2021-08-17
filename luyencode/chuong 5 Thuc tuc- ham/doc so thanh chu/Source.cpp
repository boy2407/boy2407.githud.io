#include<iostream>
#include<Windows.h>
using namespace std;
void Docsoco1chuso(int x);
void Docsoco2chuso(int x);
void Docsoco3chuso(int x);
void xuatketqua(long long int temp_p);
int Demsochuso(long long int x);
void Docsoco1chuso(int x)
{
	if (x == 0)
	{
		cout << "khong ";
	}
	else if (x == 1)
	{
		cout << "mot ";
	}
	else if (x == 2)
	{
		cout << "hai ";
	}
	else if (x == 3)
	{
		cout << "ba ";
	}
	else if (x == 4)
	{
		cout << "bon ";
	}
	else if (x == 5)
	{
		cout << "nam ";
	}
	else if (x == 6)
	{
		cout << "sau ";
	}
	else if (x == 7)
	{
		cout << "bay ";
	}
	else if (x == 8)
	{
		cout << "tam ";
	}
	else if (x == 9)
	{
		cout << "chin ";
	}
}
void Docsoco2chuso(int x)
{
	int HangChuc = x / 10;
	int HangDonVi = x % 10;
	if (HangChuc != 1)
	{
		Docsoco1chuso(HangChuc);
	}
	cout << "muoi ";
	if (HangDonVi != 0)
	{
		if (HangDonVi == 5)
		{
			cout << "lam ";
		}
		else
		{
			Docsoco1chuso(HangDonVi);
		}

	}

}
void Docsoco3chuso(int x)
{
	int HangTram = x / 100;
	int HangchucvaDonvi = x % 100;
	int Hangchu = HangchucvaDonvi / 10;
	int Donvi = HangchucvaDonvi % 10;
	Docsoco1chuso(HangTram);
	cout << "tram ";
	if (Hangchu != 0)
	{
		Docsoco2chuso(HangchucvaDonvi);
	}
	else
	{
		if (Donvi != 0)
		{
			cout << "le ";
			Docsoco1chuso(Donvi);
		}
	}
}
void DocPhuAm(int SoDauPhay)
{
	if (SoDauPhay == 1|| SoDauPhay == 4|| SoDauPhay == 7)
	{
		cout << "Nghin ";

	}
	else if (SoDauPhay == 2|| SoDauPhay == 5|| SoDauPhay == 8)
	{
		cout << "Trieu ";
	}
	else if (SoDauPhay == 3|| SoDauPhay == 6|| SoDauPhay == 9)
	{
		cout << "Ty ";
	}
}
int Demsochuso(long long int x)
{
	int dem = 0;
	if (x == 0)
	{
		dem = 1;
	}
	while (x!=0)
	{
		x /= 10;
		dem++;
	}
	return dem;
}
void xuatketqua(long long int temp_n)
{

	if (temp_n < 0)
	{
		temp_n *= -1;
		cout << "Am ";
	}

	int SoChuso = Demsochuso(temp_n);

	//tinh dau phay
	int SoDauPhay = (SoChuso - 1) / 3;

	long long int LuyThua = pow(10, 3 * SoDauPhay);

	int Cumso = temp_n / LuyThua;
	printf("%d ", SoDauPhay);
	printf("%d ", Cumso);
	printf("%d ", temp_n);
	printf("%d ", LuyThua);
	//cum so dau tien

	if (Cumso < 10)
	{
		Docsoco1chuso(Cumso);
	}
	else if (Cumso < 100)
	{
		Docsoco2chuso(Cumso);
	}
	else if (Cumso < 1000)
	{
		Docsoco3chuso(Cumso);
	}
	DocPhuAm(SoDauPhay);
	
	temp_n %= LuyThua;
	// doc cum so con lai
	while (temp_n != 0)
	{
		SoDauPhay--;
		LuyThua = pow(10, 3 * SoDauPhay);

		Cumso = temp_n / LuyThua;
		
		printf("%d ", SoDauPhay);
		printf("%d ", Cumso);
		printf("%d ", temp_n);
		printf("%d ", LuyThua);
		if (Cumso != 0)
		{
			Docsoco3chuso(Cumso);

			DocPhuAm(SoDauPhay);
		}
		temp_n %= LuyThua;
	}
}
int main()
{
	x:
	long long int n;
	do
	{
		cout << "\nNhap so :";
		cin >> n;
		if (n > LLONG_MAX)
		{
			cout << "vui long nhap lai";
			Sleep(5000);
			system("cls");
			goto x;
		}
		if (n < LLONG_MAX)
		{
			xuatketqua(n);
		}	
		
	} while (n<LLONG_MAX);
	
		
	cout << endl;
	system("pause");
	return 0;
}