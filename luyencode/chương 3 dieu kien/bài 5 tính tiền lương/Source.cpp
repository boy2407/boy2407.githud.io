#include<stdio.h>
#include<math.h>
#include<conio.h>
#define LUONG 650000
int main() {
	int TNTC;
	printf("\n nhap vao tam nien cong tac ");
	scanf_s("%d",&TNTC);
	float hesoluong;
	double luong;
	if (TNTC < 12)
	{
		hesoluong = 1.92;
		luong = hesoluong * LUONG;

	}
	else if (12<=TNTC&&TNTC<36)
	{
		hesoluong = 2.34;
		luong = hesoluong * LUONG;
	}
	else if (36 <= TNTC && TNTC < 60)
	{
		hesoluong = 3;
		luong = hesoluong * LUONG;
	}
	else
	{
		hesoluong = 4.5;
		luong = hesoluong * LUONG;
	}
	printf("%.lf", luong);
	return 0;
}