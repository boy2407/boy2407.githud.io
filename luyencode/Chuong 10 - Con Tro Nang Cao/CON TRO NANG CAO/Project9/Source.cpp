#include <stdio.h>
#include <conio.h>

int TinhTong(int a, int b)
{
	return a + b;
}

int TinhHieu(int a, int b)
{
	return a - b;
}

int TinhTich(int a, int b)
{
	return a * b;
}

int TinhThuong(int a, int b)
{
	return a / b;
}

// Trả về 1 con trỏ hàm.
int (*TinhToan(char pheptoan))(int, int)
{
	if(pheptoan == '+')
	{
		return TinhTong;
	}
	else if(pheptoan == '-')
	{
		return TinhHieu;
	}
	else if(pheptoan == '*')
	{
		return TinhTich;
	}
	return TinhThuong;
}

int main()
{
	int a = 6, b = 9;
	int Kq;

	// Tạo 1 con trỏ hàm để nhận con trỏ hàm trả về.
	int (*Pointer)(int, int);

	Pointer = TinhToan('+');
	Kq = Pointer(a, b);
	printf("\nTong = %d", Kq);

	Pointer = TinhToan('-');
	Kq = Pointer(a, b);
	printf("\nHieu = %d", Kq);

	Pointer = TinhToan('*');
	Kq = Pointer(a, b);
	printf("\nTich = %d", Kq);

	Pointer = TinhToan('/');
	Kq = Pointer(a, b);
	printf("\nThuong = %d", Kq);

	getch();
	return 0;
}