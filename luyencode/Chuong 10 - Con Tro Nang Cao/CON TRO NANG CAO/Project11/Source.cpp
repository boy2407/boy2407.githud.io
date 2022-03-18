#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void A()
{
	printf("\nDay la ham A");
}

void B()
{
	printf("\nDay la ham B");
}

void C()
{
	printf("\nDay la ham C");
}

int main()
{
	int n = 3; 

	// Khai báo.
	void (**Pointer)();

	Pointer = (void (**)())malloc(n * sizeof(*Pointer));

	Pointer[0] = A; // Cho con trỏ hàm thứ 1 trỏ tới hàm A
	Pointer[1] = B; // Cho con trỏ hàm thứ 2 trỏ tới hàm B
	Pointer[2] = C; // Cho con trỏ hàm thứ 3 trỏ tới hàm C

	Pointer[0](); // Gọi thực hiện hàm A
	Pointer[1](); // Gọi thực hiện hàm B
	Pointer[2](); // Gọi thực hiện hàm C

	getch();
	return 0;
}