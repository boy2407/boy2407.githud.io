#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 100
void XuatMang(int [][MAX], int , int );
void NhapMang(int [][MAX], int , int );

void NhapMang(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d]= ",i,j);
			scanf_s("%d", &a[i][j]);
		}
	}
}
void XuatMang(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
//===============cau 1=============
void LietKeSoChan(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (a[i][j] % 2 == 0)
				printf("%4d", a[i][j]);
		}
	}
}
//===============cau 2=============
bool  KiemTraNguyenTo(int x)
{
	if (x < 2)
	{
		return false;
	}
	else if (x>2)
	{
		if (x % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i < (int)sqrt((float)x); i += 2)
		{
			if (x % i != 0)
			{
				return false;
			}
		}
	}
	return true;
}
void LietketCacSoNguyenTo(int a[][MAX], int dong, int cot)
{
	for (int i=0; i < dong; i++)
	{
		for (int j=0; j < cot; j++)
		{
			if (KiemTraNguyenTo(a[i][j]))
			{
				printf("%4d", a[i][j]);
			}
		}
	}
}
//===============cau 3=============
bool KiemTraSoHoanThien(int x)
{
	int tong = 0;
	for (int i = 1; i <= x/2; i++)
	{
		if (x % i == 0)
		{
			tong += i;
		}
	}
	return tong = x;
}
void LietKeSoHoanThien(int a[][MAX], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (KiemTraSoHoanThien(a[i][j]))
			{
				printf("%4d", a[i][j]);
			}
		}
	}
}
int main()
{

	int a[MAX][MAX], dong, cot;
	do {

		printf("\nNhap vao so dong:");
		scanf_s("%d", &dong);

		if (dong<0 || dong>MAX)
		{
			printf("\nNhap so dong khong hop le");

		}
	} while(dong < 0||dong>MAX);
	
	do {

		printf("\nNhap vao so cot:");
		scanf_s("%d", &cot);

		if (cot < 0 || cot> MAX)
		{
			printf("\nNhap so cot khong hop le");

		}
	} while (cot < 0 || cot > MAX);

	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);
	printf("\nCac so chan la");
	LietKeSoChan(a, dong, cot);
	
	printf("\nCac so nguyen to la");
	LietketCacSoNguyenTo(a, dong, cot);


	return 0;
}
/*
			CH??NG 6: Ma Tr?n

		  * K? THU?T T�NH TO�N *

B�i 320:

float TinhTongCacSoDuong(float a[][MAX], int dong, int cot)
{
	float Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				Tong += a[i][j];
			}
		}
	}
	return Tong;
}

B�i 321:

int TinhTichCacSoLe(int a[][MAX], int dong, int cot)
{
	int Tich = 1;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 != 0)
			{
				Tich *= a[i][j];
			}
		}
	}
	return Tich;
}

B�i 322:

float TinhTongDongK(float a[][MAX], int k, int cot)
{
	float Tong = 0;

	for(int j = 0; j < cot; j++)
	{
		Tong += a[k][j];
	}

	return Tong;
}

B�i 323:

float TinhTichCacSoDuongTrenCotK(float a[][MAX], int dong, int k)
{
	float Tich = 1;

	for(int i = 0; i < dong; i++)
	{
		if(a[i][k] >= 0)
		{
			Tich *= a[i][k];
		}
	}
	return Tich;
}

B�i 324, 325 t??ng t? => t? l�m

B�i 326:

float TinhTrungBinhCongCacSoDuong(float a[][MAX], int dong, int cot)
{
	int dem = 0; // ??m s? l??ng c�c s? d??ng.
	float Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++; // T?ng bi?n ??m l�n.
				Tong += a[i][j];
			}
		}
	}
	return Tong / dem;
}

B�i 327:

float TinhTongBien(float a[][MAX], int dong, int cot)
{
	float Tong = 0;

	// T�nh t?ng c?a d�ng ??u v� d�ng cu?i.
	for(int j = 0; j < cot; j++)
	{
		Tong += (a[0][j] + a[dong - 1][j]);
	}

	// T�nh t?ng c?a c?t ??u v� c?t cu?i (b? ?i 2 � ??u v� cu?i).
	for(int i = 1; i < dong - 1; i++)
	{
		Tong += (a[i][0] + a[i][cot - 1]);
	}
	return Tong;
}

B�i 328:
#include <math.h>

// T�nh c?n b?c n c?a s? x.
float TinhCanBac_n(float x, int n)
{
	return pow(x, (float)1 / n);
}

float TinhTrungBinhNhanCacSoDuong(float a[][MAX], int dong, int cot)
{
	float Tich = 1;
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				Tich *= a[i][j];
				dem++;
			}
		}
	}
	return TinhCanBac_n(Tich, dem);
}

B�i 329:
#include <math.h>

void BienDoi(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] < 0)
			{
				a[i][j] *= -1; // Ho?c d�ng: a[i][j] = fabs(a[i][j]). L?u �: fabs tr? v? tr? tuy?t ??i c?a 1 s? th?c, c�n abs tr? v? tr? tuy?t ??i c?a s? nguy�n.
			}
		}
	}
}

B�i 331, 332: T? l�m

B�i 333:

S? ho�n thi?n l� s? m� c?ng c�c ??c s? nh? h?n n� l?i b?ng ch�nh n�.

bool KiemTraSoHoanThien(int x)
{
	int Tong = 0;

	for(int i = 1; i <= x / 2; i++)
	{
		if(x % i == 0)
		{
			Tong += i;
		}
	}

	if(Tong == x)
	{
		return true; // L� s? ho�n thi?n.
	}
	return false; // Kh�ng ph?i l� s? ho�n thi?n.
}

int TinhTongCacSoHoanThien(int a[][MAX], int dong, int cot)
{
	int Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraSoHoanThien(a[i][j]) == true)
			{
				Tong += a[i][j];
			}
		}
	}
	return Tong;
}

					* K? THU?T ??M *

B�i 334: ??m s? l??ng c�c s? d??ng c� trong ma tr?n c�c s? th?c

int DemSoLuongCacSoDuong(float a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++; // T?ng bi?n ??m l�n.
			}
		}
	}
	return dem;
}

B�i 335: ??m s? nguy�n t? trong ma tr?n c�c s? nguy�n

// S? nguy�n t? l� s? >= 2 v� ch? chia h?t cho 1 v� ch�nh n�.

bool KiemTraSoNguyenTo(int x)
{
	if(x < 2)
	{
		return false; // Kh�ng l� nguy�n t?.
	}
	else if(x > 2)
	{
		if(x % 2 == 0)
		{
			return false; // Kh�ng l� nguy�n t?.
		}
		for(int i = 3; i <= sqrt((float)x); i += 2)
		{
			if(x % i == 0)
			{
				return false; // Kh�ng l� nguy�n t?.
			}
		}
	}
	return true; // L� nguy�n t?.
}

int DemSoLuongCacSoNguyenTo(int a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(KiemTraSoNguyenTo(a[i][j]) == true)
			{
				dem++;
			}
		}
	}
	return dem;
}

B�i 336: ??m t?n su?t xu?t hi?n c?a m?t gi� tr? x trong ma tr?n c�c s? th?c

int DemTanSuatXuatHienCuaX(float a[][MAX], int dong, int cot, float x)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] == x)
			{
				dem++;
			}
		}
	}
	return dem;
}

B�i 337: ??m s? ch? s? c� trong ma tr?n c�c s? nguy�n d??ng.

vd: ma tr?n 2 x 3
12 35 5
87 0 69

=> s? ch? s?: 10

int DemSoLuongChuSoCuaX(int x)
{
	int dem = 0;

	while(x != 0)
	{
		x /= 10;
		dem++;
	}
	return dem;
}

int DemSoLuongChuSoCuaMaTran(int a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			dem += DemSoLuongChuSoCuaX(a[i][j]);
		}
	}
	return dem;
}

B�i 338: ??m s? l??ng s? d??ng tr�n 1 h�ng
B�i 339: ??m s? l??ng s? ho�n thi?n tr�n 1 h�ng
B�i 340: ??m s? l??ng s? �m tr�n 1 c?t.
B�i 341: ??m s? l??ng s? d??ng tr�n bi�n ma tr?n

=> Ho�n to�n t??ng t? c�c b�i tr??c ?�.

B�i 342 (*): ??m s? l??ng ph?n t? c?c ??i trong ma tr?n c�c s? th?c. M?t ph?n
t? ???c g?i l� c?c ??i khi n� l?n h?n c�c ph?n t? xung quanh.

B�i 343 (*): ??m s? l??ng ph?n t? c?c tr? trong ma tr?n c�c s? th?c. M?t ph?n
t? ???c g?i l� c?c tr? khi n� l?n h?n ho?c nh? h?n c�c ph?n t? xung quanh.

L�m m?u b�i 343:

#include <limits.h>

int DemSoLuongCucTri(float a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			int Max = INT_MIN;
			int Min = INT_MAX;
			// v� d? ta ?ang x�t l� a[i][j].
			=> tr�n a[i][j]: a[i - 1][j]
			=> d??i a[i][j]: a[i + 1][j]
			=> tr�i a[i][j]: a[i][j - 1]
			=> ph?i a[i][j]: a[i][j + 1]

			// X�t tr�n.
			if(i - 1 < 0)
			{
				=> l?i ko x�t.
			}
			else
			{
				Max = a[i - 1][j] > Max ? a[i - 1][j] : Max;
				Min = a[i - 1][j] < Min ? a[i - 1][j] : Min;
			}

			// X�t d??i.
			if(i + 1 == dong)
			{
				=> l?i ko x�t.
			}
			else
			{
				Max = a[i + 1][j] > Max ? a[i + 1][j] : Max;
				Min = a[i + 1][j] < Min ? a[i + 1][j] : Min;
			}

			// X�t tr�i.
			if(j - 1 < 0)
			{
				=> l?i kh�ng x�t.
			}
			else
			{
				Max = a[i][j - 1] > Max ? a[i][j - 1] : Max;
				Min = a[i][j - 1] < Min ? a[i][j - 1] : Min;
			}

			// X�t ph?i.
			if(j + 1 == cot)
			{
				=> l?i kh�ng x�t.
			}
			else
			{
				Max = a[i][j + 1] > Max ? a[i][j + 1] : Max;
				Min = a[i][j + 1] < Min ? a[i][j + 1] : Min;
			}

			if(a[i][j] > Max || a[i][j] < Min) // a[i][j] ch�nh l� c?c tr?.
			{
				dem++;
			}
		}
	}
	return dem;
}

B�i 344 (*): ??m s? l??ng gi� tr? c� trong ma tr?n c�c s? th?c.
L?u �: N?u c� k ph?n t? (k >= 1) trong ma tr?n b?ng nhau th� ta ch? t�nh 1

=> ?? b�i n�y � n�i l� ??m s? l??ng c�c ph?n t? ph�n bi?t c� trong ma tr?n.

vd: ma tr?n 2 x 3
1 2 1
1 0 0

=> c� 3 ph?n t? ph�n bi?t l�: 1, 2, 0

=> Xem trong Project Bai 344

B�i 345: T�nh t?ng c�c ph?n t? c?c tr?
=> gi?ng b�i 343

B�i 346 (*): ??m s? l??ng gi� tr? ho�ng h?u tr�n ma tr?n. M?t ph?n t? ???c g?i l� ho�ng h?u
khi n� l?n nh?t tr�n d�ng, tr�n c?t v� hai ???ng ch�o ?i qua n�.

=> G?I �:
vd: Ma tr?n ?ang x�t l� 4 x 5
a[i][j] ?ang x�t l�: a[1][2]
+ X�t d�ng ?ang ch?a n�: C? ??nh d�ng ?ang ??ng v� c?t ch?y t? 0 cho t?i c?t - 1
+ X�t c?t ?ang ch?a n�: C? ??nh c?t ?ang ??ng v� d�ng ch?y t? 0 cho t?i d�ng - 1
+ X�t ch�o ?i t? tr�n tr�i xu?ng d??i ph?i: a[0][1], a[1][2], a[2][3], a[3][4]
=> h�nh th�nh 2 ???ng ?i l�n v� ?i xu?ng. ?i l�n th� c?t v� d�ng c�ng gi?m 1, ?i xu?ng th� c?t v�
d�ng c�ng t?ng 1.
+ X�t ch�o ?i t? tr�n ph?i xu?ng d??i tr�i: a[0][3], a[1][2], a[2][1], a[3][0]
=> h�nh th�nh 2 ???ng ?i l�n v� ?i xu?ng. ?i l�n th� d�ng gi?m 1, c?t t?ng 1. ?i xu?ng th� d�ng
t?ng 1, c?t gi?m 1.

B�i 347 (*): ??m s? l??ng gi� tr? y�n ng?a tr�n ma tr?n. M?t ph?n t? ???c g?i l� y�n ng?a khi n�
l?n nh?t tr�n d�ng v� nh? nh?t tr�n c?t.

=> G?I �:
X�t d�ng v� c?t ?ang ch?a n�.
?�y ch? l� b�i con c?a b�i 346

						* K? THU?T ??T C? HI?U *

B�i 348: Ki?m tra ma tr?n c� t?n t?i s? d??ng hay kh�ng ?

// Tr? v? true n?u c� t?n t?i d??ng, ng??c l?i tr? v? false.
bool KiemTraTonTaiDuong(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				return true;
			}
		}
	}
	return false;
}

B�i 349: Ki?m tra ma tr?n c� t?n t?i s? ho�n thi?n hay kh�ng ?
=> gi?ng b�i 348

B�i 350: Ki?m tra ma tr?n c� t?n t?i s? l? hay kh�ng ?
=> gi?ng b�i 348

B�i 351: Ki?m tra ma tr?n c� to�n d??ng hay kh�ng ?
=> ch? c?n g?p th?ng �m ??u ti�n l� k?t lu?n kh�ng th?a, c�n n?u ?i t?i cu?i c�ng th� s? th?a

bool KiemTraToanDuong(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] < 0)
			{
				return false;
			}
		}
	}
	return true;
}

B�i 352: Ki?m tra 1 h�ng c� t?ng d?n hay kh�ng ?

// Ki?m tra h�ng k t?ng d?n. N?u ?�ng tr? v? true, n?u sai tr? v? false.
bool KiemTraHangTangDan(float a[][MAX], int k, int cot)
{
	for(int j = 0; j < cot - 1; j++)
	{
		if(a[k][j] > a[k][j + 1])
		{
			return false;
		}
	}
	return true; // T?ng d?n.
}

B�i 353: Ki?m tra 1 c?t gi?m d?n
=> gi?ng b�i 352

B�i 354: Ki?m tra c�c gi� tr? trong ma tr?n c� gi?m d?n theo d�ng v� c?t hay kh�ng ?
=> k?t h?p l?i 2 b�i tr�n s? ra ???c.

B�i 355: Li?t k� c�c d�ng to�n �m trong ma tr?n c�c s? th?c.

// Ki?m tra d�ng k c� to�n �m hay kh�ng ? N?u c� tr? v? true, ng??c l?i tr? v? false.

bool KiemTraToanAm(float a[][MAX], int k, int cot)
{
	for(int j = 0; j < cot; j++)
	{
		if(a[k][j] >= 0)
		{
			return false;
		}
	}
	return true;
}

void LietKe(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++) // Ch?y h?t d�ng.
	{
		if(KiemTraToanAm(a, i, cot) == true)
		{
			printf("\nDong %d thoa man toan am !", i);
		}
	}
}

B�i 360: Li?t k� c�c c?t trong ma tr?n c� ch?a s? ch�nh ph??ng

- S? ch�nh ph??ng l� s? m� k?t qu? khai c?n b?c 2 l� 1 s? nguy�n
vd: 0, 1, 4, 9, 16, 25 ...

#include <math.h>

bool KiemTraChinhPhuong(int x)
{
	return sqrt((float)x) == (int)sqrt((float)x);
}

						* K? THU?T ??T L�NH CANH *

B�i 366: T�m s? ch?n ??u ti�n xu?t hi?n trong ma tr?n s? nguy�n.

int TimSoChanDauTien(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				return a[i][j]; // S? ch?n t�m th?y.
			}
		}
	}
	return -1; // Kh�ng t?n t?i s? ch?n.
}

B�i 367: T�m gi� tr? l?n nh?t trong ma tr?n.

// C�ch n�y ch?p nh?n duy?t l?i a[0][0] th�m 1 l?n.
float TimMax_Cach1(float a[][MAX], int dong, int cot)
{
	float Max = a[0][0];
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] > Max)
			{
				Max = a[i][j];
			}
		}
	}
	return Max;
}

// C�ch n�y kh�ng c?n duy?t l?i a[0][0] m� ch? duy?t c�c ph?n t? ti?p theo.
float TimMax_Cach2(float a[][MAX], int dong, int cot)
{
	float Max = a[0][0];

	for(int i = 1; i < dong * cot; i++)
	{
		if(a[i / cot][i % cot] > Max)
		{
			Max = a[i / cot][i % cot];
		}
	}
	return Max;
}


B�i 368: T�m gi� tr? l?n th? nh� trong ma tr?n. Gi? s? ma tr?n c� nhi?u h?n hai gi� tr?.

=> C?I TI?N ?? B�I: Nh?p v�o s? k (s? l??ng ph?n t? ph�n bi?t >= k >= 1) t�m ra ph?n t?
l?n th? k trong ma tr?n

vd: Nh?p k = 1 => t�m ra ph?n t? l?n nh?t
vd: Nh?p k = 2 => t�m ra ph?n t? l?n nh�
vd: Nh?p k = 3 => t�m ra ph?n t? l?n th? 3

...


*/