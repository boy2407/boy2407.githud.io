#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<string.h>
#include<iostream>
#include"Sort.h"
using namespace std;
int MaxHoTen = 0, MaxMaSo = 0;
void NhapChuoi(char[], char[], int);
void KhoangCach(int);
struct SinhVien
{
	char  HoTen[31];
	char MaSo[31];
	float toan, li, hoa;

};
typedef struct SinhVien SINHVIEN;
float TinhDiemTrungBinh(SINHVIEN);

int DodaiHoTenLonNhat(SINHVIEN sv[],int n)
{
	int Max = strlen(sv[0].HoTen);
	for (int i = 0; i < n; ++i)
	{
		int Dodai = strlen(sv[i].HoTen);
		if (Max < Dodai)
		{
			Max = Dodai;
		}
	}
	return Max;
}
int DodaiMaSoLonNhat(SINHVIEN sv[], int n)
{
	int Max = strlen(sv[0].MaSo);
	for (int i = 0; i < n; ++i)
	{
		int Dodai = strlen(sv[i].MaSo);
		if (Max < Dodai)
		{
			Max = Dodai;
		}
	}
	return Max;
}
int khoangcach[6] = { 10,10,10,10,10,10 };
char arr[6][30] = { "Ho Ten","Ma So","Diem Toan", "Diem Ly","Diem Hoa","Diem Truong Binh" };

void XuatSinhVien(SINHVIEN sv)
{
	printf("\n%s", sv.HoTen);
	KhoangCach(khoangcach[0] - (strlen(sv.HoTen) - strlen(arr[0])));
	printf("%s", sv.MaSo);
	KhoangCach(khoangcach[1] - (strlen(sv.MaSo) - strlen(arr[1])));
	printf("%.2f", sv.toan);
	KhoangCach(khoangcach[2] - (4 - strlen(arr[2])));
	printf("%.2f", sv.li);
	KhoangCach(khoangcach[3] - (4 - strlen(arr[3])));
	printf("%.2f", sv.hoa);
	KhoangCach(khoangcach[4] - (4 - strlen(arr[4])));
	printf("%.2f",TinhDiemTrungBinh(sv));
}
float TinhDiemTrungBinh(SINHVIEN sv)
{
	return (sv.toan + sv.hoa + sv.li) / 3;
}

void NhapSinhVien(SINHVIEN &sv,int a)
{
	char tengoi1[]= "Ho ten";
	char tengoi2[] = "Ma So";
	NhapChuoi(sv.HoTen,tengoi1, sizeof(sv.HoTen));
	int DoDaiHoTen = strlen(sv.HoTen);
	if (DoDaiHoTen > MaxHoTen)
		MaxHoTen = DoDaiHoTen;
	NhapChuoi(sv.MaSo, tengoi2, sizeof(sv.MaSo));
	int DoDaiMaSo = strlen(sv.MaSo);
	if (DoDaiMaSo > MaxMaSo)
		MaxHoTen = DoDaiHoTen;
	do
	{
		printf("\nDiem toan :");
		scanf_s("%f", &sv.toan);
		if (sv.toan < 0 || sv.toan>10)
		{
			printf("\nDiem phai nam trong doan[0,10]");
		}

	} while (sv.toan<0||sv.toan>10);
	do
	{
		printf("\nDiem li :");
		scanf_s("%f", &sv.li);
		if (sv.li < 0 || sv.li>10)
		{
			printf("\nDiem phai nam trong doan[0,10]");
		}

	} while (sv.li < 0 || sv.li>10);
	do
	{

		printf("\nDiem hoa :");
		scanf_s("%f", &sv.hoa);
		if (sv.hoa < 0 || sv.hoa>10)
		{
			printf("\nDiem phai nam trong doan[0,10]");
		}

	} while (sv.hoa < 0 || sv.hoa>10);
}
//template <class T>
//void HoanVi(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//
//	//printf("\ngan trong ham HoanVi => gan = %d", gan);
//}
bool operator<(SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) < TinhDiemTrungBinh(b);		
}
bool operator<=(SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) <= TinhDiemTrungBinh(b);
}
bool operator>(SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) > TinhDiemTrungBinh(b);
}
bool operator==(SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) == TinhDiemTrungBinh(b);
}
bool operator!=(SINHVIEN a, SINHVIEN b)
{
	return TinhDiemTrungBinh(a) != TinhDiemTrungBinh(b);
}
// kieusapxep là true: tăng - false: giảm
//template <class T>
//void SelectionSort(T*& sv, int n, bool sortup = true)
//{
//	for (int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Min bắt đầu từ i
//	{
//		int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i
//
//		//printf("\ngan vong lap i => i = %d => gan = %d", i, gan);
//
//		for (int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
//		{
//
//		//	if (a[j] < a[vitriMin] == kieusapxep) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
//			if(TinhDiemTrungBinh(sv[j])<TinhDiemTrungBinh(sv[vitriMin]))
//			{
//
//				vitriMin = j; // cập nhật lại vị trí Min
//
//				//printf("\ngan vong lap j => j = %d => gan = %d", j, gan);
//			}
//		}
//		HoanVi(sv[i], sv[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
//	}
//}
void NhapDanhSachSinhVien(SINHVIEN*& sv, int &n)
{
	do
	{
		printf("\nNhap So Luong Sinh Vien:");
		scanf_s("%d", &n);
		if (n <= 0)
		{
			printf("\nSo Luong Sai ");
		}
	} while (n <= 0);

	sv = new SINHVIEN[n];

	for (int i = 0; i < n; ++i)
	{
		printf("\n====>Nhap Thong Tinh Sinh Vien Thu %d", i + 1);
		NhapSinhVien(sv[i],i);
	}
}
void XuatDanhSach(SINHVIEN* sv, int n)
{
	//printf("\nHo Ten \t\t Ma So  \t Diem Toan\t Diem Li\t Diem Hoa \tDiem Trung Binh");

	//xuat ra cot
	for (int i = 0; i < 6; ++i)
	{
		printf("%s", arr[i]);
		KhoangCach(khoangcach[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		XuatSinhVien(sv[i]);
	}
}
void NhapChuoi(char chuoi[], char tengoi[], int size)
{
	printf("\nNhap vao %s (toi da %d ky tu): ", tengoi, size - 1);
	int dem = 0;
	char c;
	while (true)
	{
		c = _getch();
		if (c == 13)	// 13 là mã ascii của phím Enter
			break; // thoát khỏi vòng lặp

		else if (c == 8) // 8 là mã ascii của phím BackSpce (xóa) trên bàn phím
		{
			if (dem != 0)
				dem--;

			chuoi[dem] = '\0'; // Xóa ký tự cuối cùng hiện tại
			system("cls"); // xóa toàn bộ màn hình hiện tại đi
			printf("\nNhap vao %s (toi da %d ky tu): ", tengoi, size - 1);
			printf("%s", chuoi);
		}
		else // Khác Enter và Khác BackSpace
		{
			if (dem < size - 1)
			{
				printf("%c", c);
				chuoi[dem] = c;
				dem++;
			}
			else // dem == sizeof(HoTen) - 1
				printf("\nBan khong duoc phep nhap them do da toi ky tu cuoi cung duoc phep. Xac nhan nhap xong nhan phim Enter");
		}
	}
	chuoi[dem] = '\0'; // Kết thúc chuỗi
}
void KhoangCach(int n)
{
	for (int i = 1; i <=n; ++i)
	{
		printf(" ");
	}
}
int main()
{
	SINHVIEN* sv;
	int n;
	NhapDanhSachSinhVien(sv,n);
	/*khoangcach[0] += DodaiHoTenLonNhat(sv, n);
	khoangcach[1] += DodaiMaSoLonNhat(sv, n);*/

	khoangcach[0] += MaxHoTen;
	khoangcach[1] += MaxMaSo;
	XuatDanhSach(sv, n);
	SelectionSort(sv, n, true);
	XuatDanhSach(sv, n);
	return 0;

}
