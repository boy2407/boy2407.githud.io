#include<stdio.h>
#include<conio.h>

#include<stdlib.h>
#include<iostream>
using namespace std;

struct SinhVien
{
	char MaSo[10];
	char HoTen[30];
	float Diem;
};
typedef struct SinhVien SINHVIEN;

void NhapTongTinSinhVien(SINHVIEN &sv)
{
	char x;
	while ((x = getchar()) != '\n' && x != EOF);
	printf("\nNhap vao ma so :");
	gets_s(sv.MaSo);

	fflush(stdin);
	printf("\nNhap Ho Ten :");
	gets_s(sv.HoTen);

	
	printf("\nNhap Diem :");
	scanf_s("%f", &sv.Diem);
	
}

void NhapDanhSachLop(SINHVIEN* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap thong tin sinh vien thu %d", i+1);
		NhapTongTinSinhVien(arr[i]);
	}
}
void GhiFile(FILE *&FileOut, SINHVIEN* arr, int n)
{
	FileOut = fopen("DanhSachLop.DOC", "wb");

	if (!FileOut)
	{
		fwrite(arr, sizeof(SINHVIEN), n, FileOut);
	}

	fclose(FileOut);
}

void XuatThongTinSinhSinh(SINHVIEN sv)
{
	printf("\nMa so: %s", sv.MaSo);
	printf("\nTen sinh vien %s ", sv.HoTen);
	printf("\nDiem %f ", sv.Diem);
}
void XuatDanhSachLop(SINHVIEN* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		XuatThongTinSinhSinh(arr[i]);
	}
}
void DocFile(FILE*& FileIn, SINHVIEN*& arr, int& n)
{
	FileIn = fopen("DanhSachLop.DOC", "rb");

	if (!FileIn)
	{
		printf("\nKhong Tim thay tap tin");

		exit(0);
	}
	fseek(FileIn, 0, SEEK_END);
	n = (ftell(FileIn) + 1) / sizeof(SINHVIEN);
	rewind(FileIn);
	arr = (SINHVIEN*)malloc(n * sizeof(SINHVIEN));
	fread(arr, sizeof(SINHVIEN), n, FileIn);
	fclose(FileIn);
}
int main()
{
	int n = 3;
	SINHVIEN* arr = (SINHVIEN*)malloc(n * sizeof(SINHVIEN));
	SINHVIEN sv1, sv2, sv3;

	NhapDanhSachLop(arr, n);
	
	FILE* FileOut;
	GhiFile(FileOut, arr, n);

	/*FILE* FileIn;
	DocFile(FileIn, arr, n);*/
	XuatDanhSachLop(arr, n);
	free(arr);
	return 0;
}