#include <stdio.h>
#include <conio.h>

int main()
{
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

	printf("\nsizeof(a) = %d", sizeof(a));
	printf("\nsizeof(a[0]) = %d", sizeof(a[0]));
	printf("\nsizeof(a[0][0]) = %d", sizeof(a[0][0]));

	printf("\nMuon truy xuat toi o a[1][2] co cac cach sau: ");
	printf("\nCach 1: a[1][2] = %d", a[1][2]);
	printf("\nCach 2: *(a[1] + 2) = %d", *(a[1] + 2));
	printf("\nCach 3: *(*(a + 1) + 2) = %d", *(*(a + 1) + 2));


	getch();
	return 0;
}