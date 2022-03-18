#include <iostream>
using namespace std;

void A()
{
	cout << "\nDay la ham A";
}

void B()
{
	cout << "\nDay la ham B";
}

void C()
{
	cout << "\nDay la ham C";
}

void main()
{
	// Khởi tạo con trỏ hàm.
	void (*Pointer)();

	Pointer = A; // Con trỏ hàm trỏ tới hàm A.

	cout << "\nDia chi cua ham A la: " << &A;
	cout << "\nDia chi cua con tro la: " << &Pointer;
	cout << "\nMien gia tri cua con tro la: " << Pointer;

	Pointer();

	system("pause");
}