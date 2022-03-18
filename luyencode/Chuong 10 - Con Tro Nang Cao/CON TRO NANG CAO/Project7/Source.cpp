#include <stdio.h>
#include <conio.h>

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
	// Khai báo con trỏ hàm.
	void (*Pointer)();

	// Con trỏ hàm trỏ tới hàm A
	Pointer = C; // Có thể rút gọn bằng cách: Pointer = A;
	Pointer = A;
	Pointer = B;

	// Gọi thực hiện con trỏ hàm.
	(*Pointer)(); // Có thể rút gọn bằng cách Pointer();

	if(Pointer == A)
	{
		printf("\nCon tro dang tro toi ham A");
	}
	if(Pointer == B)
	{
		printf("\nCon tro dang tro toi ham B");
	}
	if(Pointer == C)
	{
		printf("\nCon tro dang tro toi ham C");
	}

	getch();
	return 0;
}