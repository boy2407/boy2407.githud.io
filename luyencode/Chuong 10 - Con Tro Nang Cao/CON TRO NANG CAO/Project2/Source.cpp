#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void NhapMang(int **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("\nNhap vao a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
			// Cách 2: scanf("%d", a[i] + j);
			// Cách 3: scanf("%d", *(a + i) + j)
		}
	}
}

void XuatMang(int **a, int dong, int cot)
{
	for(int i = 0; i < dong; i++)
	{
		for(int j = 0; j < cot; j++)
		{
			printf("%4d", a[i][j]);
			// Cách 2: printf("%4d", *(a[i] + j))
			// Cách 3: printf("%4d", *(*(a + i) + j))
		}
		printf("\n");
	}
}

int main()
{
	int dong = 2, cot = 3;
	int **a; // Khai báo con trỏ cấp 2.

	/* ============ CẤP PHÁT BỘ NHỚ CHO MẢNG 2 CHIỀU =========== */

	// Tạo ra các con trỏ quản lý đầu mỗi dòng.
	a = (int **)malloc(dong * sizeof(int));

	// Với những con trỏ quản lý đầu mỗi dòng lại tạo ra các phần tử bên trong đó.
	for(int i = 0; i < dong; i++)
	{
		a[i] = (int *)malloc(cot * sizeof(int));
	}

	/* ======================================= */

	// Xử lý
	NhapMang(a, dong, cot);
	XuatMang(a, dong, cot);

	/* ============== GIẢI PHÓNG BỘ NHỚ =========== */
	
	// Giai phong tung phan tu ben trong moi dong
	for(int i = 0; i < dong; i++)
	{
		free(a[i]);
	}

	// giai phong tat ca con tro quan ly dau moi dong
	free(a);

	getch();
	return 0;
}