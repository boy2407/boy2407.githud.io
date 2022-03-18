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

int main()
{
	int a = 5, b = 6;

	// Tạo con trỏ hàm.
	int (*Pointer)(int, int);

	// Trỏ tới hàm TinhTong
	Pointer = TinhTong;

	// Lấy kết quả xuất ra màn hình.
	int Kq = Pointer(a, b);
	printf("\nTong la: %d", Kq);

	Pointer = TinhHieu;
	Kq = Pointer(a, b);
	printf("\nHieu la: %d", Kq);

	Pointer = TinhTich;
	Kq = Pointer(a, b);
	printf("\nTich la: %d", Kq);

	Pointer = TinhThuong;
	Kq = Pointer(a, b);
	printf("\nThuong la: %d", Kq);

	getch();
	return 0;
}





