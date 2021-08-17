#include<iostream>
#include<fstream>
using namespace std;
struct SinhVien
{
	char MaSo[10];
	char HoTen[30];
	float Diem;
};
typedef struct SinhVien SINHVIEN;

void XuatThongTinSinhVien(SINHVIEN sv)
{
	cout << "\nMa so: %s"<<sv.MaSo;
	cout<<"\nHo ten: %s"<< sv.HoTen;
	cout << "\nDiem: %f" << sv.Diem;
}

void XuatDanhSachLop(SINHVIEN* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		XuatThongTinSinhVien(arr[i]);
	}
}

void DocFile(ifstream &FileIn, SINHVIEN*& arr, int& n)
{
	FileIn.open("DanhSachLop.DOC", ios_base::in);

	if (!FileIn)
	{
		cout<<"\nKhong tim thay tap tin DanhSachLop.DOC";

		exit(0);
	}

	FileIn.seekg(0, ios::end);
	n = ((int)FileIn.tellg()+1) / sizeof(SINHVIEN);
	FileIn.seekg(0, ios::beg);

	arr = new SINHVIEN[n];
	FileIn.read((char *)arr, n * sizeof(SINHVIEN));

	FileIn.close();
}

bool LonHon(SINHVIEN a, SINHVIEN b)
{
	return a.Diem > b.Diem;
}

bool NhoHon(SINHVIEN a, SINHVIEN b)
{
	return a.Diem < b.Diem;
}

void HoanVi(SINHVIEN& a, SINHVIEN& b)
{
	SINHVIEN Temp = a;
	a = b;
	b = Temp;
}void SapXep(SINHVIEN* arr, int n, bool (*SoSanh)(SINHVIEN, SINHVIEN))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SoSanh(arr[i], arr[j]) == true)
			{
				HoanVi(arr[i], arr[j]);
			}
		}
	}
}
SINHVIEN TimSinhVienThoaYeuCau(SINHVIEN* arr, int n, bool (*SoSanh)(SINHVIEN, SINHVIEN))
{
	SINHVIEN x = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (SoSanh(arr[i], x) == true)
		{
			x = arr[i];
		}
	}
	return x;
}

int main()
{
	SINHVIEN* arr;
	int n;
	ifstream FileIn;

	DocFile(FileIn, arr, n);
	XuatDanhSachLop(arr, n);

	/*printf("\nSap xep tang\n");
	SapXep(arr, n, LonHon);
	XuatDanhSachLop(arr, n);

	printf("\nSap xep giam\n");
	SapXep(arr, n, NhoHon);
	XuatDanhSachLop(arr, n);

	SINHVIEN Max = TimSinhVienThoaYeuCau(arr, n, LonHon);
	SINHVIEN Min = TimSinhVienThoaYeuCau(arr, n, NhoHon);

	printf("\nThong tin sinh vien co diem trung binh cao nhat la\n");
	XuatThongTinSinhVien(Max);

	printf("\nThong tin sinh vien co diem trung binh thap nhat la\n");
	XuatThongTinSinhVien(Min);*/


	return 0;
}