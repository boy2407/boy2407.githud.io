#include <iostream>
#include <string>
using namespace std;

template <class SonDepTrai>
void HoanVi(SonDepTrai &a, SonDepTrai &b)
{
	SonDepTrai Temp = a;
	a = b;
	b = Temp;
}

int main()
{
	string a = "Nam", b = "Son";

	HoanVi<string>(a, b);

	cout << "\na = " << a << " & b = " << b;
	
	system("pause");
	return 0;
}