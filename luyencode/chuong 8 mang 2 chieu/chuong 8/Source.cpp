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

		  * K? THU?T TÍNH TOÁN *

Bài 320:

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

Bài 321:

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

Bài 322:

float TinhTongDongK(float a[][MAX], int k, int cot)
{
	float Tong = 0;

	for(int j = 0; j < cot; j++)
	{
		Tong += a[k][j];
	}

	return Tong;
}

Bài 323:

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

Bài 324, 325 t??ng t? => t? làm

Bài 326:

float TinhTrungBinhCongCacSoDuong(float a[][MAX], int dong, int cot)
{
	int dem = 0; // ??m s? l??ng các s? d??ng.
	float Tong = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++; // T?ng bi?n ??m lên.
				Tong += a[i][j];
			}
		}
	}
	return Tong / dem;
}

Bài 327:

float TinhTongBien(float a[][MAX], int dong, int cot)
{
	float Tong = 0;

	// Tính t?ng c?a dòng ??u và dòng cu?i.
	for(int j = 0; j < cot; j++)
	{
		Tong += (a[0][j] + a[dong - 1][j]);
	}

	// Tính t?ng c?a c?t ??u và c?t cu?i (b? ?i 2 ô ??u và cu?i).
	for(int i = 1; i < dong - 1; i++)
	{
		Tong += (a[i][0] + a[i][cot - 1]);
	}
	return Tong;
}

Bài 328:
#include <math.h>

// Tính c?n b?c n c?a s? x.
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

Bài 329:
#include <math.h>

void BienDoi(float a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] < 0)
			{
				a[i][j] *= -1; // Ho?c dùng: a[i][j] = fabs(a[i][j]). L?u ý: fabs tr? v? tr? tuy?t ??i c?a 1 s? th?c, còn abs tr? v? tr? tuy?t ??i c?a s? nguyên.
			}
		}
	}
}

Bài 331, 332: T? làm

Bài 333:

S? hoàn thi?n là s? mà c?ng các ??c s? nh? h?n nó l?i b?ng chính nó.

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
		return true; // Là s? hoàn thi?n.
	}
	return false; // Không ph?i là s? hoàn thi?n.
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

Bài 334: ??m s? l??ng các s? d??ng có trong ma tr?n các s? th?c

int DemSoLuongCacSoDuong(float a[][MAX], int dong, int cot)
{
	int dem = 0;

	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] >= 0)
			{
				dem++; // T?ng bi?n ??m lên.
			}
		}
	}
	return dem;
}

Bài 335: ??m s? nguyên t? trong ma tr?n các s? nguyên

// S? nguyên t? là s? >= 2 và ch? chia h?t cho 1 và chính nó.

bool KiemTraSoNguyenTo(int x)
{
	if(x < 2)
	{
		return false; // Không là nguyên t?.
	}
	else if(x > 2)
	{
		if(x % 2 == 0)
		{
			return false; // Không là nguyên t?.
		}
		for(int i = 3; i <= sqrt((float)x); i += 2)
		{
			if(x % i == 0)
			{
				return false; // Không là nguyên t?.
			}
		}
	}
	return true; // Là nguyên t?.
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

Bài 336: ??m t?n su?t xu?t hi?n c?a m?t giá tr? x trong ma tr?n các s? th?c

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

Bài 337: ??m s? ch? s? có trong ma tr?n các s? nguyên d??ng.

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

Bài 338: ??m s? l??ng s? d??ng trên 1 hàng
Bài 339: ??m s? l??ng s? hoàn thi?n trên 1 hàng
Bài 340: ??m s? l??ng s? âm trên 1 c?t.
Bài 341: ??m s? l??ng s? d??ng trên biên ma tr?n

=> Hoàn toàn t??ng t? các bài tr??c ?ó.

Bài 342 (*): ??m s? l??ng ph?n t? c?c ??i trong ma tr?n các s? th?c. M?t ph?n
t? ???c g?i là c?c ??i khi nó l?n h?n các ph?n t? xung quanh.

Bài 343 (*): ??m s? l??ng ph?n t? c?c tr? trong ma tr?n các s? th?c. M?t ph?n
t? ???c g?i là c?c tr? khi nó l?n h?n ho?c nh? h?n các ph?n t? xung quanh.

Làm m?u bài 343:

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
			// ví d? ta ?ang xét là a[i][j].
			=> trên a[i][j]: a[i - 1][j]
			=> d??i a[i][j]: a[i + 1][j]
			=> trái a[i][j]: a[i][j - 1]
			=> ph?i a[i][j]: a[i][j + 1]

			// Xét trên.
			if(i - 1 < 0)
			{
				=> l?i ko xét.
			}
			else
			{
				Max = a[i - 1][j] > Max ? a[i - 1][j] : Max;
				Min = a[i - 1][j] < Min ? a[i - 1][j] : Min;
			}

			// Xét d??i.
			if(i + 1 == dong)
			{
				=> l?i ko xét.
			}
			else
			{
				Max = a[i + 1][j] > Max ? a[i + 1][j] : Max;
				Min = a[i + 1][j] < Min ? a[i + 1][j] : Min;
			}

			// Xét trái.
			if(j - 1 < 0)
			{
				=> l?i không xét.
			}
			else
			{
				Max = a[i][j - 1] > Max ? a[i][j - 1] : Max;
				Min = a[i][j - 1] < Min ? a[i][j - 1] : Min;
			}

			// Xét ph?i.
			if(j + 1 == cot)
			{
				=> l?i không xét.
			}
			else
			{
				Max = a[i][j + 1] > Max ? a[i][j + 1] : Max;
				Min = a[i][j + 1] < Min ? a[i][j + 1] : Min;
			}

			if(a[i][j] > Max || a[i][j] < Min) // a[i][j] chính là c?c tr?.
			{
				dem++;
			}
		}
	}
	return dem;
}

Bài 344 (*): ??m s? l??ng giá tr? có trong ma tr?n các s? th?c.
L?u ý: N?u có k ph?n t? (k >= 1) trong ma tr?n b?ng nhau thì ta ch? tính 1

=> ?? bài này ý nói là ??m s? l??ng các ph?n t? phân bi?t có trong ma tr?n.

vd: ma tr?n 2 x 3
1 2 1
1 0 0

=> có 3 ph?n t? phân bi?t là: 1, 2, 0

=> Xem trong Project Bai 344

Bài 345: Tính t?ng các ph?n t? c?c tr?
=> gi?ng bài 343

Bài 346 (*): ??m s? l??ng giá tr? hoàng h?u trên ma tr?n. M?t ph?n t? ???c g?i là hoàng h?u
khi nó l?n nh?t trên dòng, trên c?t và hai ???ng chéo ?i qua nó.

=> G?I Ý:
vd: Ma tr?n ?ang xét là 4 x 5
a[i][j] ?ang xét là: a[1][2]
+ Xét dòng ?ang ch?a nó: C? ??nh dòng ?ang ??ng và c?t ch?y t? 0 cho t?i c?t - 1
+ Xét c?t ?ang ch?a nó: C? ??nh c?t ?ang ??ng và dòng ch?y t? 0 cho t?i dòng - 1
+ Xét chéo ?i t? trên trái xu?ng d??i ph?i: a[0][1], a[1][2], a[2][3], a[3][4]
=> hình thành 2 ???ng ?i lên và ?i xu?ng. ?i lên thì c?t và dòng cùng gi?m 1, ?i xu?ng thì c?t và
dòng cùng t?ng 1.
+ Xét chéo ?i t? trên ph?i xu?ng d??i trái: a[0][3], a[1][2], a[2][1], a[3][0]
=> hình thành 2 ???ng ?i lên và ?i xu?ng. ?i lên thì dòng gi?m 1, c?t t?ng 1. ?i xu?ng thì dòng
t?ng 1, c?t gi?m 1.

Bài 347 (*): ??m s? l??ng giá tr? yên ng?a trên ma tr?n. M?t ph?n t? ???c g?i là yên ng?a khi nó
l?n nh?t trên dòng và nh? nh?t trên c?t.

=> G?I Ý:
Xét dòng và c?t ?ang ch?a nó.
?ây ch? là bài con c?a bài 346

						* K? THU?T ??T C? HI?U *

Bài 348: Ki?m tra ma tr?n có t?n t?i s? d??ng hay không ?

// Tr? v? true n?u có t?n t?i d??ng, ng??c l?i tr? v? false.
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

Bài 349: Ki?m tra ma tr?n có t?n t?i s? hoàn thi?n hay không ?
=> gi?ng bài 348

Bài 350: Ki?m tra ma tr?n có t?n t?i s? l? hay không ?
=> gi?ng bài 348

Bài 351: Ki?m tra ma tr?n có toàn d??ng hay không ?
=> ch? c?n g?p th?ng âm ??u tiên là k?t lu?n không th?a, còn n?u ?i t?i cu?i cùng thì s? th?a

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

Bài 352: Ki?m tra 1 hàng có t?ng d?n hay không ?

// Ki?m tra hàng k t?ng d?n. N?u ?úng tr? v? true, n?u sai tr? v? false.
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

Bài 353: Ki?m tra 1 c?t gi?m d?n
=> gi?ng bài 352

Bài 354: Ki?m tra các giá tr? trong ma tr?n có gi?m d?n theo dòng và c?t hay không ?
=> k?t h?p l?i 2 bài trên s? ra ???c.

Bài 355: Li?t kê các dòng toàn âm trong ma tr?n các s? th?c.

// Ki?m tra dòng k có toàn âm hay không ? N?u có tr? v? true, ng??c l?i tr? v? false.

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
	for(int i = 0; i < dong; i++) // Ch?y h?t dòng.
	{
		if(KiemTraToanAm(a, i, cot) == true)
		{
			printf("\nDong %d thoa man toan am !", i);
		}
	}
}

Bài 360: Li?t kê các c?t trong ma tr?n có ch?a s? chính ph??ng

- S? chính ph??ng là s? mà k?t qu? khai c?n b?c 2 là 1 s? nguyên
vd: 0, 1, 4, 9, 16, 25 ...

#include <math.h>

bool KiemTraChinhPhuong(int x)
{
	return sqrt((float)x) == (int)sqrt((float)x);
}

						* K? THU?T ??T LÍNH CANH *

Bài 366: Tìm s? ch?n ??u tiên xu?t hi?n trong ma tr?n s? nguyên.

int TimSoChanDauTien(int a[][MAX], int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				return a[i][j]; // S? ch?n tìm th?y.
			}
		}
	}
	return -1; // Không t?n t?i s? ch?n.
}

Bài 367: Tìm giá tr? l?n nh?t trong ma tr?n.

// Cách này ch?p nh?n duy?t l?i a[0][0] thêm 1 l?n.
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

// Cách này không c?n duy?t l?i a[0][0] mà ch? duy?t các ph?n t? ti?p theo.
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


Bài 368: Tìm giá tr? l?n th? nhì trong ma tr?n. Gi? s? ma tr?n có nhi?u h?n hai giá tr?.

=> C?I TI?N ?? BÀI: Nh?p vào s? k (s? l??ng ph?n t? phân bi?t >= k >= 1) tìm ra ph?n t?
l?n th? k trong ma tr?n

vd: Nh?p k = 1 => tìm ra ph?n t? l?n nh?t
vd: Nh?p k = 2 => tìm ra ph?n t? l?n nhì
vd: Nh?p k = 3 => tìm ra ph?n t? l?n th? 3

...


*/