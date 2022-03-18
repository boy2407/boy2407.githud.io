#include <iostream>
using namespace std;

void NhapMang(int **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			cout << "\nNhap vao a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
			// Cách 2: cin >> *(a[i] + j);
			// Cách 3: cin >> *(*(a + i) + j);
		}
	}
}

void XuatMang(int **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			cout << a[i][j] << "    ";
			// Cách 2:  cout <<  *(a[i] + j));
			// Cách 3: cout << *(*(a + i) + j));
		}
		cout << endl;
	}
}

int main()
{
	int dong = 2, cot = 3;
	int **a; // Khai báo con trỏ cấp 2.

	/* ============ CẤP PHÁT BỘ NHỚ CHO MẢNG 2 CHIỀU =========== */

	// Tạo ra các con trỏ quản lý đầu mỗi dòng.
	a = new int*[dong];

	// Với những con trỏ quản lý đầu mỗi dòng lại tạo ra các phần tử bên trong đó.
	for(int i = 0; i < dong; i++)
	{
		a[i] = new int[cot];
	}

	/* ======================================= */

	// Xử lý
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);

	/* ============== GIẢI PHÓNG BỘ NHỚ =========== */
	
	// Giai phong tung phan tu ben trong moi dong
	for(int i = 0; i < dong; i++)
	{
		delete[] a[i];
	}
	
	// giai phong tat ca con tro quan ly dau moi dong
	delete[] a;

	system("pause");
	return 0;
}