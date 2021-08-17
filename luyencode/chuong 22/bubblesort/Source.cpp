#include<iostream>
using namespace std;
template <class T>
void HoanVi(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <class abc>
void XuatMang(abc* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("\n%d = %2d", i, a[i]);

}
template<class T>
void BubbleSort(T* a, int n, bool kieusapxep = true)
{
	for (int i = 0; i <= n - 2; ++i)
	{
		bool check = true;
		for (int j = n - 1; j > i; --j)
		{

			if (a[j - 1] > a[j] == kieusapxep)
			{
				HoanVi(a[j - 1], a[j]);
				check = false;
			}
			if (check)
			{
				break;
			}
		}
	}
}
int main()
{
	int a[] = { 3,1,4,0,5,7,10};
	int n =sizeof(a)/sizeof(a[0]) ;
	XuatMang<int>(a, n);

	BubbleSort(a, n);
	cout << "\nsau khi sap xep :";
	XuatMang(a, n);

	return 0;
}